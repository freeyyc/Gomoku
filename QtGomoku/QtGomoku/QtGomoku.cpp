#include "QtGomoku.h"
#include <QGraphicsItem>
#include <QPointF>
#include <csignal>
#include <qDebug>
#include <QMessageBox>
#include <QFile>
#include <QString>


/*
 * 构造和初始化
 */
QtGomoku::QtGomoku(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setFixedSize(this->width(), this->height());  //这种最好。
	m_scene = new BoardScene(ui.BoardView);
	connect(m_scene, SIGNAL(BoardSenseMouseRelease(QPoint*)), this, SLOT(OnMouseReleaseOnBoardSense(QPoint*)));
	m_scene->setSceneRect(0, 0
		, static_cast<QWidget *>(m_scene->parent())->size().width()
		, static_cast<QWidget *>(m_scene->parent())->size().height());
	ui.BoardView->setScene(m_scene);

	WhiteStone = new QPixmap(":/QtGomoku/Resources/white.png");
	BlackStone = new QPixmap(":/QtGomoku/Resources/black.png");
	for(int i=0;i<GRID_NUM;i++)
	{
		for (int j=0;j<GRID_NUM;j++)
		{
			BoardMap[i][j] = space;
		}
	}
	//m_ai = new AiAgent();
	//connect(this, SIGNAL(IsTimeForAiToCalculate(POINT*)), m_ai, SLOT(GetAiAction(POINT*)));
	//connect(m_ai, SIGNAL(AIComplete(POINT*)), this, SLOT(OnAiComplete(POINT*)));
	robot = new Robot();
	connect(this, SIGNAL(IsTimeForAiToCalculate(POINT*)), robot, SLOT(getAiResponse(POINT*)), Qt::QueuedConnection);
	connect(robot, SIGNAL(AIComplete(POINT*)), this, SLOT(OnAiComplete(POINT*)), Qt::QueuedConnection);
	Count = 1;
}
/*
 * 鼠标在棋盘上空释放(玩家下棋)
 */
void QtGomoku::OnMouseReleaseOnBoardSense(QPoint* pos)
{
	if (CurrentTurn == Human)
	{
		int qx = pos->x() / 40;
		int qy = pos->y() / 40;

		PutDownStone(qx, qy);//人类完成落子
		POINT * _humanPos = new  POINT;
		_humanPos->x = qx;
		_humanPos->y = qy;
		if(isGameOver()==true)//游戏不能继续,不通知AI,禁用该函数禁止玩家继续落子
		{
			CurrentTurn == GameOver;//禁用该函数
			//玩家胜利
			QMessageBox::information(this, QStringLiteral("恭喜"), QStringLiteral("您打败了AI!"));
		}
		else//如果游戏还能继续,则通知AI进行计算
		{
			emit IsTimeForAiToCalculate(_humanPos);
			ui.statusBar->showMessage(QStringLiteral("AI正在计算..."));
		}
		//qDebug() << "emit IsTimeForAiToCalculate, human pos:("<< qx << ","<<qy<<")";
	}
}
/*
 * 根据当前棋局数组刷新整个画面
 */
void QtGomoku::UpdateWholeBoardView()
{
	m_scene->clear();
	for (int i=0;i<GRID_NUM;i++)
	{
		for(int j=0;j<GRID_NUM;j++)
		{
			QGraphicsPixmapItem* Black = new QGraphicsPixmapItem(*BlackStone);
			QGraphicsPixmapItem* White = new QGraphicsPixmapItem(*WhiteStone);
			switch(BoardMap[i][j])
			{
			case white:
				White->setPos(QPoint(i * 40, j * 40));
				m_scene->addItem(White);
				break;
			case black:
				Black->setPos(QPoint(i * 40, j * 40));
				m_scene->addItem(Black);
				break;
			case space:
				break;
			default:
				break;
			}
		}
	}
}
/*
 * 在(x,y)点(x和y∈[0,14])落下指定一方的棋子,并交换棋权
 */
void QtGomoku::PutDownStone(int x, int y)
{
	if(x<0||y<0||x>14||y>>14)
	{
		QMessageBox::information(this, QStringLiteral("错误!"), QStringLiteral("落子坐标非法!"));
		return;
	}
	if (BoardMap[x][y]!=space)
	{
		QMessageBox::information(this, QStringLiteral("错误!"), QStringLiteral("落子坐标已经有其他棋子!"));
		return;
	}
	//这个位置是空的
	QGraphicsPixmapItem *qpi;
	QGraphicsTextItem *txtitem = new QGraphicsTextItem(QString::fromStdString(std::to_string(Count)));
	txtitem->setFont(QFont("Microsoft YaHei", 12, QFont::Normal));
	if(CurrentTurn == Human)//人类玩家下棋
	{
		BoardMap[x][y] = HumanColor;
		qpi = new QGraphicsPixmapItem((HumanColor == black ? *BlackStone : *WhiteStone));
		CurrentTurn = Ai;
		QString temp = QStringLiteral("玩家:  x:");temp.append(QString::fromStdString(std::to_string(x))); temp.append(",y:"); temp.append(QString::fromStdString(std::to_string(y)));
		ui.listWidget_History->addItem(temp);
		txtitem->setDefaultTextColor((HumanColor == black ? QColor(255, 255, 255) : QColor(0, 0, 0)));
	}
	else
	{
		BoardMap[x][y] = AiColor;
		qpi = new QGraphicsPixmapItem((AiColor == black ? *BlackStone : *WhiteStone));
		CurrentTurn = Human;
		QString temp = QStringLiteral("AI:  x:"); temp.append(QString::fromStdString(std::to_string(x))); temp.append(",y:"); temp.append(QString::fromStdString(std::to_string(y)));
		ui.listWidget_History->addItem(temp);
		txtitem->setDefaultTextColor((HumanColor == black ?  QColor(0, 0, 0): QColor(255, 255, 255)));
	}
	ui.listWidget_History->scrollToBottom();
	qpi->setPos(QPoint(x * 40, y * 40));
	m_scene->addItem(qpi);
	int xaddin = (Count <= 9 && Count >= 0 ? 11 : (Count >= 10 && Count <= 99 ? 7.2 : 3.4));
	txtitem->setPos(QPoint(x * 40+ xaddin, y * 40+5.5));//设置要放置的的位置//x轴偏置量需要按照位数计算
	m_scene->addItem(txtitem);//添加item到scene上
	Count++;
}
/*
 * 判断游戏是否结束
 */
bool QtGomoku::isGameOver()
{
	/*
	 * 全局搜索,跳过没有棋子的点
	 */
	//遍历这个棋子横竖撇捺四个方向,发现连五判赢
	int vCount = 0, hCount = 0, lCount = 0, rCount = 0;
	for (int x=0;x<GRID_NUM;x++)
	{
		for (int y = 0; y < GRID_NUM; y++)
		{
			if(BoardMap[x][y]==space)
			{
				continue;
			}
			Color _color = BoardMap[x][y];//当前落子的颜色
			for (int i = 0; i < GRID_NUM; i++)//水平和竖直
			{
				hCount = (BoardMap[i][y] == _color ? hCount + 1 : 0);
				vCount = (BoardMap[x][i] == _color ? vCount + 1 : 0);
				if (vCount >= 5 || hCount >= 5)
				{
					return true;//游戏已经结束
				}

			}
			int m = GRID_NUM - abs(x - y);//主对角线方向元素数量
			int n = GRID_NUM - abs(GRID_NUM - (x + y + 1));//次对角线方向元素数量
			for (int i = -std::min(x, y); i < m - std::min(x, y); i++)
			{
				rCount = (BoardMap[x + i][y + i] == _color ? rCount + 1 : 0);//主对角线方向
				if (rCount >= 5)
				{
					return true;//游戏已经结束
				}
			}
			int imax = n + (x - y) - 1 - std::min(x, GRID_NUM - 1 - y);
			int jmax = n - imax;
			for (int i = -imax; i < jmax; i++)
			{
				lCount = (BoardMap[x - i][y + i] == _color ? lCount + 1 : 0);//次对角线方向
				if (lCount >= 5)
				{
					return true;//游戏已经结束
				}
			}
		}
	}
	return false;//游戏还没有结束
}
/*
 * 相应AI计算完毕
 */
void QtGomoku::OnAiComplete(POINT * pos)
{
	qDebug() << "OnAiComplete is running...";
	PutDownStone(pos->x, pos->y);
	if (isGameOver() == true)//游戏不能继续,禁止玩家落子
	{
		CurrentTurn = GameOver;//游戏终止
		//AI胜利
		QMessageBox::information(this, QStringLiteral("很遗憾"), QStringLiteral("AI已经取胜!"));
	}		
	ui.statusBar->clearMessage();
	ui.statusBar->showMessage(QStringLiteral("AI计算完毕!"));
}
/*
 * 按键:新游戏
 */
void QtGomoku::OnNewGame()
{
}
/*
 * 按键:悔棋
 */
void QtGomoku::OnUndo()
{
}
/*
 * 按键:结束游戏
 */
void QtGomoku::OnStopGame()
{
}
/*
 * 按键:帮助
 */
void QtGomoku::OnHelp()
{
}
/*
 * 单选:玩家执黑
 */
void QtGomoku::OnCheckedHumanBlack()
{
}
/*
 * 单选:玩家执白
 */
void QtGomoku::OnCheckedHumanWhite()
{
}
/*
 * 单选:启动禁手
 */
void QtGomoku::OnCheckedEnableForbidden()
{
}
/*
 * 单选:关闭禁手
 */
void QtGomoku::OnCheckedUnableForbidden()
{
}
/*
 * 单选:开启声音
 */
void QtGomoku::OnCheckedSoundOn()
{
}
/*
 * 单选:关闭声音
 */
void QtGomoku::OnCheckedSoundOff()
{
}
/*
 * 单选:人机对战
 */
void QtGomoku::OnCheckedPVE()
{
}
/*
 * 单选:人人对战
 */
void QtGomoku::OnCheckedPVP()
{
}
