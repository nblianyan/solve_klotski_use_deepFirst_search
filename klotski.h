/*
*	作者：李安晏
*	邮箱：nblianyan@qq.com
*	日期：2018-3-31
*	功能描述：使用深度优先搜索解算数字华容道
*/




#ifndef __KLOTSKI_H
#define __KLOTSKI_H 

typedef struct klotski_struct_1 Type_KlotskiNode;
typedef enum klotski_enum_1 Enum_Operate;


extern int PUBLIC_KlotskiNodeID ;
extern short PUBLIC_TargetArray[3][3];
extern int PUBLIC_TreeDepth;
extern int PUBLIC_KlotskiInputArray[3][3];
extern Type_KlotskiNode InputNode ;

/*
名称：struct klotski_struct_1
功能：用以描述深度优先搜索所使用的“树”中的节点
*/
struct klotski_struct_1	
{
	int NodeID;								//节点ID，每个节点ID全局唯一
	int TreeDepth;							//当前节点所在的树中的位置的深度
	Enum_Operate lastOperation;				//上一层生成本节点所使用的操作
	short Array[3][3];						//核心部分，记录本节点的矩阵
	Type_KlotskiNode * preNode;				//指针，指向父节点
	Type_KlotskiNode * nextNode[4];			//指针数组，用以指向子节点
};


/*
名称：enum klotski_enum_1
功能：用以描述某节点生成子节点所执行的操作
*/
enum klotski_enum_1	
{
	OperationDown = 0,						//数字“0” 向下移动
	OperationUp   = 1,						//数字“0” 向上移动
	OperationRight= 2,						//数字“0” 向右移动
	OperationLeft = 3,						//数字“0” 向左移动
	OperationNone = 4						//数字“0” 无操作
};


/*--------------------------------------------------------------------------------------------------------------
名称：klotski_tree_create_child_node
参数：FatherNode,用以生成子节点的节点的指针
返回值：无意义
*/
int klotski_tree_create_child_node(Type_KlotskiNode * FatherNode);

/*--------------------------------------------------------------------------------------------------------------
名称：klotski_tree_init_node
参数：	node，需要初始化的子节点的指针
		Position_X,父节点的矩阵中数字“0”的位置的行数
		Position_Y,父节点的矩阵中数字“0”的位置的列数
		Operation，需要对子节点执行的操作
返回值：无意义
功能：	根据Operation对 node节点中的数据进行初始化
*/
int klotski_tree_init_node(Type_KlotskiNode * node, int Position_X, int Position_Y, Enum_Operate Operate);

/*---------------------------------------------------------------------------------------------------------------
名称：klotski_tree_malloc_2_child_node
参数：无
返回值：指向申请成功地内存的地址，或者NULL
功能：为子节点申请Type_KlotskiNode类型的地址空间
*/
Type_KlotskiNode * klotski_tree_malloc_2_child_node(void);

/*--------------------------------------------------------------------------------------------------------------
名称：klotski_check_child_node
参数：父节点指针
返回值：无
功能：检查FatherNode的子节点指针是否异常
*/
void klotski_check_child_node(Type_KlotskiNode * FatherNode);

/*---------------------------------------------------------------------------------------------------------------
名称：klotski_tree_create_tree
参数：TreeHead,树的顶点
	  TreeDepth,希望生成的树的深度
返回值：无意义
功能：生成以 TreeHead为顶点、深度为TreeDepth 的树
*/
int klotski_tree_create_tree(Type_KlotskiNode * TreeHead, int TreeDepth);
/*--------------------------------------------------------------------------------------------------------------
名称：klotski_compare_node2target
参数：Node,需要进行比较的节点
返回值： 0，与目标状态不相等；
		 1，与目标状态相等
功能：将Node节点与目标进行比较，判断是否相同
*/
int klotski_compare_node2target(Type_KlotskiNode * Node);
/*-------------------------------------------------------------------------------------------------------------
名称：print_succeful_path
参数：TailNode 树的末端节点
返回值：无
功能：在控制台打印生成目标所经过的节点路径
*/
void print_succeful_path(Type_KlotskiNode * TailNode);
/*------------------------------------------------------------------------------------------------------------
名称：print_node
参数：Node，需要显示的节点
返回值：无
功能：将指定节点的矩阵打印
*/
void print_node(Type_KlotskiNode * Node);
/*------------------------------------------------------------------------------------------------------------
名称：klotski_seed_same_node
参数：  NowNode,需要寻找相同节点的原节点
		FatherNode,需要与NowNode进行比较的节点树的末端节点
返回值：1，存在相同节点
		0，不存在相同节点
功能：在FatherNode节点及其父系所有的节点中寻找与NowNode节点的矩阵相同的节点
*/
int klotski_seek_same_node(Type_KlotskiNode * NowNode, Type_KlotskiNode * FatherNode); //1:存在 2：不存在

/*-----------------------------------------------------------------------------------------------------------
名称：klotski_compare_node2node
参数：NowNode，需要进行比较的原节点
	  LastNode，需要进行比较的节点
返回值：0，不相同
		1，相同
功能：将NowNode节点与LastNode节点的矩阵进行比较
*/
int klotski_compare_node2node(Type_KlotskiNode * NowNode, Type_KlotskiNode * LastNode);
/*
名称：klotski_get_input
功能：获取输入信息
*/
void klotski_get_input(void);
/*
功能：开始任务
*/
void klotski_start(void);

#endif
