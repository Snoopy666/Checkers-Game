#ifndef CHECKERSGAME_H
#define CHECKERSGAME_H

#include <QObject>
#include <QVector>
#include <vector>
#include <ctime>
#include "checkersstate.h"

// 游戏规则类型
enum GameType{
	RUSSIAN = 1,
	INTERNATIONAL = 2,
};

class CheckersGame : public QObject
{
	Q_OBJECT
public:
    CheckersGame();
	~CheckersGame();
    bool setGameType(int type);		// 设置相应游戏类型
	void setMaxLevel(int level);
    void startNewGame(int color);		// 开始新的比赛，电脑颜色
	void endGame();
public slots:
	void setClicked(int i, int j);
	void historyShowFirst();
	void historyShowLast();
	void historyShowPrev();
	void historyShowNext();
signals:
    void stateChanged(CheckersState *);	// 改变状态，需要复制
	void vectorChanged(std::vector <point> & v);
	void vectorDeleted();
	void gameEnded(uint8);
private:
    void firstClick(int i, int j);		// 玩家第一次点击
    void secondClick(int i, int j);		// 玩家第二次点击

    // AI
    void go();										// 执行步骤的电脑当前状态
    int goRecursive(CheckersState * state, int level, int alpha, int beta);	// 构建递归搜索树
    void calcCounts(CheckersState * state);
    int evaluation(CheckersState * state);			// 状态评估函数
    void pp(CheckersState * state, uint8 color);	// 生成方法
    bool checkTerminatePosition(CheckersState * state);	// 检查终点位置
	int movesCount(CheckersState * state, int i, int j);
    int searchMove(CheckersState * state, int i, int j, std::vector <point> & vp); // 寻找可行路线
    bool checkCoordinate(char x);					// 坐标检查身份
	void clearTree(CheckersState * state, bool clearlists = true, bool onlychilds = false);
	void clearTreeRecursive(CheckersState * state, bool clearlists = false);
    bool move(point p1, point p2);						//
	uint8 whoWin(CheckersState * state);

    std::vector <std::vector <point> > history;
	std::vector <CheckersState *> historyStates;
	int historynum;
	void historyShow();

	std::vector <CheckersState *> movesearch;
    std::vector < point > tmpvector;	// 不同点存的临时向量
	point tmppoint;
	void printPointVector(std::vector <point> & v);

    CheckersState * first;			// 初始状态
    CheckersState * current;		// 当前状态
	CheckersState * tmp;
    int n;						// 大小
    int k_start;						// 开始时行数
    int type;						// 游戏类型（R,I）
    int computercolor;			// 电脑颜色
    int humancolor;				// 玩家颜色

    int level;						// 树的深度
    int click;					// 点击
    char ix[4];						// 绕行方向
    char jx[4];						// 在搜索阶段使用
    // 控制搜索约束的各种标志等：
	bool capturefound;
	bool calccounts;
    bool gamerunning;				// 游戏正在运行
    int maxlevel;				// 最大搜索层数

    // 状态计数
	int cleared;
	int created;
};

#endif // CHECKERSGAME_H
