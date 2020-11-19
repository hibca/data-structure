/*


！！！！！！！！！！！
表，树，
重点理解：哈夫曼树


*/


//顺序表
//顺序表插入操作
bool InsertList(SqList &L,int ,ElemType e)
{
	if(i<1 || i>L.length +1)	//判断位置是否有效
	{
		printf("位置无效\n");
		return false;
	}
	if (L.length >= MaxSize)	//判断存储空间是否已满
	{
		printf("当前存储空间已满\n");
		return false;
	}
	for (int j = L.length; j >=i; j--)//位置i及之后元素后移
	{
		L.data[j] = L.data[j-1];
	}
	L.data[i-1] = e;
	L.length++;
	return true;
}


-----------------------------------------------------------------
删除操作
-----------------------------------------------------------------
bool ListDelete(SqList &L,int i)
{
	if (i<1 || i>L.length)
	{
		printf(" 位置无效\n");
		return false;
	}
	for (int j=i;j<=L.length - 1;j++)//位置i之后元素依次前移覆盖
	{
		L.data[j-1] = L.data[j];
	}
	L.length--;
	return true;
}

-----------------------------------------------------------------
顺序查找
-----------------------------------------------------------------
int LocateElem(SqList L,ElemType)
{
	for(int i=0;i<L.length;i++)	//从低位置查找
	{
		if(L.data[i]==e)
			return i+1;
	}
	return 0;
}
*****************************************************************
链表
*****************************************************************
单链表插入结点
-----------------------------------------------------------------
/*函数功能：在链表中插入元素
  输入：head链表头指针，p新元素插入位置，x新元素中的数据域内容
  返回值：无
*/
void insert(Node *head,int p,int x)
{
	Node *tmp=head;	
	for(int i=0;i<p;i++)
	{
		if(tmp==NULL)
			return;
		if(i<p-1)
			tmp=tmp->next;
	}//防止插入位置超出了链表长度
	Node *tmp2=newNode;
	tmp2 ->data=x;
	tmp2 ->next=tmp->next;
	tmp->next=tmp2;
}
-----------------------------------------------------------------
单链表删除结点操作
-----------------------------------------------------------------
/*函数功能：删除链表中的元素
  输入：head链表头指针，p被删除元素位置
  返回值：被删除元素中的数据域，如果失败返回-1*/
intdel(Node *head,int p)
{
	Node *tmp=head;
	for(int i=0;i<p;i++)
	{
		if(tmp==NULL)
			return -1;
		if(i<p-1)
			tmp=tmp->next;
	}
	int ret=tmp->next->data;
	tmp->next=tmp->next->next;
	return ret;
}


*****************************************************************
双链表操作
*****************************************************************
双链表元素插入
-----------------------------------------------------------------
/*在带头结点的双链循环线性表L中第i个位置之前插入元素e,i的合法值为1<=i<=表长+1*/
Status ListInsert(DuLinkList L, int i, ElemType e) {
	DulinkList p, s;
	if (i<1 || i>ListLength(L) + 1)			//i值不合法
		return ERROR;
	p = GetElemP(L, i - 1);				//在L中确定第i个元素前驱的位置指针p
	if (!P)						//p=null，即第i个元素前驱不存在（设头结点为第1个元素的前驱）
		return ERROR;
		s = (DulinkList)malloc(sizeof(DuLNode));
		if (!s)
			return OVERFLOW;
		s->data = e;
		s->prior = p;				//在第i-1个元素之后插入
		s->next = p -> next;
		p->next->prior = s;
		p->next = s;
		return ok;
}

-----------------------------------------------------------------
双链表删除
-----------------------------------------------------------------
/*删除带头结点的双循环线性表L的第i个元素，i的合法值为1<=i<-表长*/
Status ListDelete(DuLinkList L,int i,ElemType *e)
{
	DuLinkList p;
	if(i<0)
	{
		return ERROR;
	}
	p=GetElemP(L,i);
	if(!p)
	{
		return ERROR;
	}
	*e = p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(P);
	return ok;
}
------------------------------------------------------------------------------------------
|				双链表插入总结										  |
------------------------------------------------------------------------------------------ |
****************************************************************************************** |
*在p之后插入s	    |	p之前插入s		|	删除p之后继s	|	 删除p之后继s    |
********************************************************************************************|
*p->next->prior=s;	|p->prior->next=s;	|s=p->next;	   |			    |
*s->next=p->next;	|s->prior=p->prior;	|p->next=s->next;  |p->prior->next=p->next; |	
*p->next=s;		|s->next=p;		|p->next->prior=p; |p->next->prior=p->prior;|
*s->prior=p;		|p->next=s;		|		   |	  		    |
*********************************************************************************************
/*例一：*/
//利用线性表实现集合的并
void union(List& La, List Lb)
{
	la_len = listlength(La);
	lb_len = listlength(lb);
	for (i = 1; i <= lb_len; i++) {
		getelem(lb, I, e);
		if (!locateelem(la, e, equal))
			listinsert(la, ++la_len, e);
	}
}
/*例二：*/
//将两表元素归并为一新表，并按值非递减有序排列
void mergelist(list la, lisa lb, list& lc)
{
	initlist(lc);
	i = j = 1;
	k = 0;
	la_len = listlength(la);
	lb_len = listlength(lb);
	while ((i<=la_len)&&(j<=lb_len))
	{
		getelem(la, I, ai);
		getelem(lb, j, bj);
		if (ai <= bj)
		{
			listinsert(lc, ++k, ai);
			++i;
		}
		else {
			listinsert(lc, ++k,bj);
			++j;
		}
	}
	while (i <= la_len)
	{
		getelem(la, i++, ai);
		listinsert(lc, ++k, ai);
	}
	while (j <= lb_len)
	{
		getelem(lb, j++, bj);
		listinsert(lc, ++k, bi);
	}
}
/*例三：插入运算*/
//在表的第i（1<=i<=n+1)个位置上插入一个新结点x
void insertList(Sqllist* L, DataType x, int i)
{
	int j;
	//判断插入点i的位置是否在范围内
	if (i<1 || i>l.length + 1) {
		printf("Position error");
		return error;
	}
	if (l.length >= ListSize) {
		printf("overflow");
		exit(overflow);
	}
	//判断插入结点的大小
	for (j=l.length-1;j>=i-1;j--)
	{
		l.data[j + 1] = data[j];
		l.data[i - 1] = x;
		l.length++;
	}//插入结点
}
/*例四：线性表的删除运算：将表第i（1<=i<=n)的结点删除*/
void deleteList(Sqlist* L, int i)
{
	int j;
	if (i<1 || i>l.length) {
		printf("position error");
		return error;
	}//判断范围
	for (j= i; j <= l.length; j++)
	{
		l.data[j - 1] = data[j];
		l.length--;
	}
}
/*例五：头插法建单链表*/
LNode* create_LinkList(void)
{
	//头插法创建单链表，链表的头结点head作为返回值
	int data;
	LNode* head, * p;
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;//创建链表的表头结点head
	int n;
	scanf("%d", &n);//共插入n个结点
	while (n--) {
		scanf("%d", &data);
		p = (LNode*)malloc(sizeof(LNode));
		p->data = data;
		p->next = head->next;
		head->next = p;
	}//构链，新创建的结点总是作为第一个结点
	return (head);

}

/*尾插法建单链表*/
LNode* create_LinkList(void)
{
	//尾插法创建单链表，链表的头结点head作为返回值
	int data;
	LNode* head, * p, * q;
	head = p = (LNode*)malloc(sizeof(LNode));
	p->next = NULL;//创建单链表的表头结点head
	int n;
	while (n--)
	{
		scanf(: % d, &data);
		q = (LNode*)malloc(sizeof(LNode));//构链，新创建的结点总是作为最后一个节点
		q->data = data;
		q->next = NULL;
		p->next = q;
		p = q;
	}
	return (head);
}

/*单链表的插入运算*/
/***********************************************
思路：
	插入运算十将值为x的新结点插入到表的第i个节
	点的位置上，即插入到ai-1与ai之间。因此，必须线找
	到ai-1的存储位置p，然后生成一个数据域为x的新结点
	*p，并令结点*p的指针域指向新结点，新结点的指针域
	指向结点ai。从而实现三个结点ai-1，x和ai之间的逻辑
	关系变化。
************************************************/
void Insertnode(linklist head, datetype x, int i)
{
	listnode* p, * q;
	p = getnode(head, i - 1);
	if (p == NULL) {
		error("position error");
		return;
	}
	q = (listnode*)malloc(sizeof(listnode));
	q->data = x;
	q->next = p->next;
	p->next = q;
}

/*单链表的删除*/
void Deletelist(linklist head, int i)
{
	listnode* p, * r;
	p = getnode(head, i - 1);
	if (p == NULL || p->next == NULL)
		return ERROR;
	r = p->next;
	p->next = r->next;
	free(r);
}
/*双链表的前插和删除*/
void Dinsertbefor(dlistnode* p, datatype x)
{
	dlistnode* q = (dlistnode*)malloc(sizeof(dlistnode));
	q->data = x;
	q->prior = p->prior;
	q->next = p;
	p->prior->next = q;
	p->prior = q;
 }

void deletenode(dlistnode* p)
{
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
}

/*例十：在带头结点的单链表L中，删除所有值为X的结点，并释放其空间，建设值为X的结点不唯一*/
void Del_X(LinkList& L, int x)
{
	if (L->next == NULL)
	{
		return;
	}
	LNode* p, * q;
	p = L;
	while (p->next != NULL)
	{
		if (p->next->data == x)
		{
			q = p->next;
			p->next = q->next;
			delete q;
		}
		else
		{
			p = p->next;
		}
	}
}
		/*栈和队列*/
/************************************************
-------------------------------------------------
定义：
	栈：只允许在一端进行插入或删除的操作的线性表
	栈定：线性表允许进行插入和删除的那一端
	栈底：固定的，不允许进行插入和删除的另一端
	空栈：不含有任何元素的空表
-------------------------------------------------
栈的基本操作：
	InitStack（&s);初始化一个空栈
	StackEmpty(S);判断一个栈是否为空
	Push(&S,x)进栈，若栈s未满，将x加入使之成为新栈顶
	Pop(&S,x)出栈，若栈S非空，弹出栈定元素，用x返回栈定元素
	GetTop(S,&T)读取栈定元素
	Clear Stack（&S）销毁栈
*************************************************/
/*基本操作：进栈*/
int push(SqStack& S, int e)
{
	if (S.top == Max_Size - 1)
	{
		return 0;
	}//判断是否满栈
	++(S.top);//先移动再进栈
	S.data[S.top] = e;
	return 1;
}
//读栈定元素
Bool GetTop(SqStack S, ElemType& x)
{
	if (S.top == -1)
	{
		return 0;
	}
	x = S, data[S.top];
	return true;
}
/**************************************************
栈和递归再运行被调函数前，必须要完成：
	1.将所有的实参，地址等信息传递给被调用函数保存
	2.为被调函数的局部变量分配空间
	3.将控制转移到被调用函数的入口
***************************************************/

/**************************************************
队列：
	是一种特殊的线性表，他只允许在表的前端（front）
	进行操作，而表的后端（rear)进行插入操作，和栈一样，队
	列是一种操作受限制的线性表，进行插入操作的端为队尾，
	进行删除操作的端称为对头。
队头（Front）：
	允许删除的一端，又称队首
队尾（Rear）：
	允许插入的一端
空队列：
	不含任何元素的空表
----------------------------------------------------
对列常见的操作：
	InitQueue(&Q):初始化队列
	QueueEmpty(Q):判断对空
	EnQueu(&Q,x):入队，若队列Q未满，将x加入，使之成为新的队尾
	DeQueue（&Q，&x）出队，若队列Q未空，则将队头元素删除，并用x返回
	GetHead（Q，&x）读取对头元素，若队列Q未空，则将对头元素赋值给x
***************************************************/
/*链队列的基本算法*/
//（1）构造空队列
Status InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = (QElemPtr)malloc(sizeof(QNode));
	if (!Q.front)
		exit(overflow);
	Q.front->next = NULL;
	return ok;
}
//(2)销毁对列
Status DestroyQueue(LinkQueue& Q)
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return ok;
}
//（3）插入元素
Status EnQueue(LinkQueue& Q, QElemtype e)
{
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return ok;
}
//(4)删除对头元素
Status DnQueue(LinkQueue& Q, QElemType& e)
{
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return ok;
}
/*****************************************
判断队列空间是否是空或满的方法
	（1）另设一个标志位以区别队列是空或满
	（2）用一个元素空间，约定以：队列头指针在队
	列尾指针的下一个位置上作为队列呈满状态的标志
	（3）使用计数器记录队列中的元素个数
******************************************/
/******************************************
------------------------------------------
线性表、栈队列的异同
相同点：
	都是线性结构、逻辑结构的概念，都是
	可以用顺序存储或链式存储。栈和队列是两种特
	殊的线性表，即受限的线性表，只是对插入删除
	运算加以限制
不同点：
	（1）运算规则不同：线性表为随机存取，而栈
	只允许在一端进行插入删除运算，因而是后进先
	出表；队列只允许一端进行插入，另一端进行删
	除运算，因而是先进先出。
	（2）用途不同：堆栈用于子程序调用和保护现场；
	队列用于多道作业处理，指令等寄存等。
------------------------------------------
******************************************/
/*循环队列顺序存储注意事项*/
//初始时：
	Q.front = Q, rear = 0
//队首指针进1：
	Q.fron=(Q.front+1)%MaxSize
//队尾指针进1：
	Q.rear=(Q.rear+1)%MaxSize
//队满条件：
	(Q.rear+1)%MaxSize==Q.front
//对空条件：
	Q,front==Q,rear
//队列中的元素个数：
	(Q.rear-Q.front+MaxSize)%MaxSize

//循环队列的操作 
	//顺序存储入队
	bool EnQueue(SqQueue* Q, QElem Type e)
	{
		//入队列
		if ((Q->rear + 1) % MaxSize == Q->front)
		{
			return false;
		}
		Q->data[Q->rear] = e;
		Q->rear = (Q->rear + 1) % MaxSize;
		//rear向后移动一位若到最后则移动至数组头
		return 1;
	}
	//顺序存储出队
	bool DeQueue(SqQueue* Q, QElemType* e)
	{
		if (Q->rear == Q->front)
		{
			return false;
		}
		*e = Q->data[Q->front];
		Q->front = (Q->front + 1) % MaxSize;
		return 1;
	}
	//链式存储入队
	void EnQueue(LinkQueue& Q, ElemType x)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = x;
		s->next = NULl;
		Q->rear->next = s;
		Q.rear = s;
	}
	//链式存储出栈
	Bool DeQueue(LinkQueue& Q, ElemType& x)
	{
		if (Q.front == Q.rear)
			return false;
		p = Q.front->next;
		x = p->data;
		Q.front->next = p->next;
		if (Q.rear == p)
		{
			Q.rear = Q.front;
		}
		free(p);
		return true;
	}
/***********************************
		使用循环队列的意义
在常规意义下，顺序存储结构的一维数组
表示队列，由于队列的性质为队尾插入和
队头删除，容易造成“假溢出”现象，即
队尾已经达到一维数组的高下标，不能入
队，然而队列中元素个数小于队列长度。
循环队列是解决“假溢出”的一种方法。
**********************************/

/**********************************
栈和队列的应用
***********************************/
//数值转换（进位转换）
void conversion(int n, int d)
{
	//将十进制整数N转换为d（2或8）进制数
	SqStack S;
	int k, * e;
	S = Init_Stack();
	while (n > 0)
	{
		k = n % d;
		push(S, k);
		n = n / d;
	}
	while (S.top != 0)
	{
		k = n % d;
		push(S, k);
		n = n / d;
	}
	//求出所有的余数，进栈
	while (S.top != 0)
	{
		pop(S, e);
		printf("%ld", *e);
	}//栈不空时出栈，输出
}
//括号匹配问题：
#define TRUE 0
#define FLASE -1
SqStack S;
S = Init_Stack();							//堆栈初始化
int Match_Brackets()
{
	char ch, x;
	scanf("%c", &ch);
	while (asc(ch) != 13)
	{
		if ((ch == '(') || ch == '[')
			push(S, ch);
		else if (ch == ']')
		{
			x == pop(S);
			if (x != '[')
			{
				printf("'['括号不匹配");
				return FLASE;
			}
		}
		else if(ch==')')
		{
			x = pop(S);
			if (x != '(')
			{
				printf("'('括号不匹配");
				return FLASE;
			}
		}
	}
	if (S.top != 0)
	{
		printf("括号数量不匹配！");
		return FLASE;
	}
	else
	{
		return TRUE;
	}

}


/**********************************************************************************************
-----------------------------------------------------------------------------------------------
解题思路：
	用栈具有的先进后出的固有特性作为程序设计中常用的工具和数据结构
	数制转换思路：
		十进制整数N向其他进制数d（二，八，十六）的转换，是计算机实现计算机的基本问题，
		转换法则：
			n=(n div d)*d + n mod d
			其中：div为整除运算，mod为求余运算
			（采用静态顺序栈方式实现）
		括号匹配问题：
			匹配思想：
				从左至右扫描一个字符串（或表达式），则每个右括号将与最近遇到的那个左括号相匹配
				则可以在从左至右扫描过程中把所有遇到的左括号存放到堆栈中。每当遇到一个右括号时
				就将它与栈顶的左括号（如果存在）相匹配，同时从栈顶删除该左括号。
			算法思想：
				设置一个栈，当读到左括号时，左括号进栈。当读到右括号时，则从栈中弹出一个元素，
				与读到的左括号进行匹配，若匹配成功，继续读入，否额匹配失败，返回fleas；
	栈在程序设语言中实现递归调用
		递归调用：
			一个函数（或过程）直接或间接的调用自身，简称递（Recursive）。递归是程序设计中的
			一个强大的工具，因为递归函数结构清晰，程序易读，正确性容易得到证明。
			为使递归调用不至于无终止地进行下去，实际上有效的递归调用函数（或过程）应包含：递推
			规则（方法），终止条件。
-----------------------------------------------------------------------------------------------
***********************************************************************************************/
/*
典型例题：
	例一
		设有编号为1、2、3、4的4辆车，顺序进入一个栈式结构的站台，试写出这4辆车开出站台的所有可能顺序
		1 2 3 4		1 2 4 3		1 3 2 4		1 3 4 2		1 4 3 2		2 1 3 4		2 1 4 3
		2 3 1 4		2 3 4 1		2 3 4 1		3 2 1 4		3 2 4 1		3 4 1 2		4 3 2 1
	例二
		已知L是无头结点的单链表，且p结点既不是第一个结点，也不是最后一个结点，从下列语句中组和出合适的语句序列
		
		①p->next=s;
		②p->next=p->next->next;
		③p->next=s->next;
		④s->next=p->next;
		⑤s->next=L;
		⑥s->next=p;
		⑦s->next=NULL;
		⑧q=p;
		⑨while(p->next!=q)p=p->next;
		⑩while(p->next!=NULL)p=p->nexr;
		⑪p=q;
		⑫p=L;
		⑬L=s;
		⑭L=p;
		(1)在p结点之后插入s结点（4）（1）
		(2)在p结点之前插入s结点（8)(12)(9)(4)(1)
		(3)在单链表L首插入s结点（5）（13）
		(4)在单链表L后插入s结点（12）（10）（7）（1）
	例三
		已知p结点是某双向链表的中间结点，试从下列提供的语句中选出合适的语句序列
		①p->next=p->next->next;
		②p->prior=p->prior->prior;
		③p->next=s;
		④p->prior=s;
		⑤s->next=p;
		⑥s->prior=p;
		⑦s->next=p->next;
		⑧s->prior=p->prior;
		⑨p->prior=p->next;
		⑩p->prior->next=p;
		⑪p->next->prior=p;
		⑫p->next->prior=s;
		⑬p->prior->next-s;
		⑭p->next->prior=p->prior;
		⑮q=p->nexet;
		⑯q=p->prior;
		⑰free(p);
		⑱free(q);
		(1)在p结点之后插入s结点：（12）（7）（3）（6）
		(2)在p结点之前插入s结点：（5）（8）（13）（4）或（8）（5）（4）（13）
		(3)删除p结点的直接后继结点：（15）（1）（11）（18）
		(4)删除p结点的直接前驱结点：（16）（2）（10）（18）

*/

/******************************************************************************
------------------------------------------------------------------------------
串：
		定义：由零个或多个字符组成的有限序列
	字符串的三种存储结构：
		（1）定长顺序存储表示：定长顺序表示，也称为静态存储分配的顺应表。它是用
		一组连续的存储单元来存放串中的字符序列。
		定长顺序存储结构，是直接使用定长的字符数组来定义的，数组的上界预先给出
		（2）堆分配存储表示：这种存储表示的特点是，仍以一组地址连续的存储单元存
		储单元存放串值字符序列，但它们的存储空间是在程序执行过程中动态分配而成
		所以也称为动态存储分配的顺序表
		（3）串的链式存储结构：顺序串上的插入和删除操作不方便，需要移动大量的字
		符。故可用单链表方式来存储串值，串的链式存储结构简称链串。
------------------------------------------------------------------------------
******************************************************************************/

/******************************************************************************
------------------------------------------------------------------------------
数组和广义表：

	矩阵压缩存取方法：
			在数值分析中常出现高阶矩阵，同时在矩阵中有许多值相同的元素或者是零
		元素，为了节省空间，可以对这类矩阵进行压缩存储。
			压缩存储：为多个值相同的元素分配一个存储空间，对零元素不分配空间。
	特殊矩阵压缩：
		对称矩阵（symmetric matrices）：指对角线为对称轴，各元素对应相等的矩阵
		下三角矩阵
		三角矩阵
		对角矩阵
		
	广义表定义：
			是元素为原子或子表的有序列，满足线性结构的特征：在非空线性结构中只
		有一个称为“第一元素”只有一个称为“最后元素”，第一个元素只有后继，没
		有前驱，最后一个元素只有前驱没有后继，其余元素都有唯一的前驱和后继，从
		这个意义上说，广义表属于线性结构，只有元素可以是原子也可以是子表。
			若广义表LS非空时：al（表中第一个元素）称为表头，其余元素组成的子表
		称为表尾；（a2,a3,..,an）广义表中包含的元素（包括原子和子表）的个数称为
		表达长度，广义表中括号的最大层数称为表深（度）
		（技巧：表深度为括号的个数）
------------------------------------------------------------------------------
******************************************************************************/

/*****************************************************************************
*数组和线性表之间的关系：												   	 *
	数组是具有相同性质的数据元素的集合，同时每个元素又有唯一的下标限定。即：（
数组是值和下标偶对的有限集合。N维数组中的每个元素，处于n个关系之中，每个关系都
是线性的，且n维数组可以看成其元素n-1维数组的一个线性表，数组一般不做插入和删除
操作，可以看成线性表的推广。
******************************************************************************/

/*****************************************************************************
*线性表和广义表的区别：
	线性表中的元素是各种各样的，但必须具有相同性质，且属于同一数据对象，
	广义表中元素可以是原子，也可以是子表
******************************************************************************/

//🔸🔸🔸🔸🔸
//树和二叉树
/******************************************************************************
树：
	1.是n（n>=0)个结点的有限集T，T为空（n=0)时称为空树，否则满足：
		1)有且仅有一个特定的称为根的结点
		2)其余的结点可以分为m(m>=0)个互不相交的子集，其中每个子集又是一棵树，并
	称其为子树。
	2.结点的度：一个结点的子树的数量称为结点的度
	3.树的度：树中结点最大的度数
	4.树的深度：树的最大层数（树的高度）
	
	基本性质：
		树的结点树为所有结点度数加1（加根结点）
		度为m的树中第i层最多有m^(i+1)个结点
		高度为h的m次树至多（m^h-1)/(m-1)个结点
		具有n个结点的m次树的最小高度为log m (n(m-1)+1)	向上取整

二叉树：
	二叉树是由n（n>=0)个结点的有限集合构成，此集合或者为空集或者由一个根节点及两
颗互不相交的左右子树组成，左右子树都是二叉树，并且其次序不能颠倒。

叶子结点、非叶子结点：
	树中度为0的结点称为叶子结点（或终端结点）。相对应的，度部位0的结点称为非叶子
结点（或非终端结点或分支结点）。除根结点外，分支结点又称为内部结点。

孩子结点、双亲结点、兄弟结点：
	一个结点的子树的根称为该节点的孩子结点或子结点，对应的，该节点是其孩子结点的
双亲结点，或父结点。同一双亲结点的所有子结点互称为兄弟结点。

结点的层次路径、祖先、子孙：
	从根节点开始，到达某节点p所经过的所有结点称为结点p的层次路径（有且只有一条）
结点p的层次路径上的所有结点（除p外）称为p祖先，以某一节点为根的子树中的任意结点
称为该节点的子孙结点。

有序树和无序树：
	对于一棵树，若其中每一个结点的子树（若有）具有一定的次序，则称为有序树，否则
称为无序树。
*******************************************************************************/


/******************************************************************************
节点和结点的区别是：
	1.节点是一个实体，它具有处理的能力；2、结点是一个交叉点、一个标记，算法中的
点一般都称为结点，数据集合中的每一个数据元素都用中间标有元素值的方框来表示，我们
称它为结点。
	2.节点是一个实体具有处理的能力；而结点是一个交叉点，是一个标记，一般算法中的
点都称为结点。
	3.在链表数据结构中，链表中每一个元素称为“结点”，每个结点都应包括两个部分：
一个是需要用的实际数据data；另一个就是存储下一个结点地址的指针，即数据域和指针域
。数据结构中的每一个数据结点对应于一个存储单元，这种储存单元称为储存结点，也可简
称结点。
*******************************************************************************/
 


/******************************************************************************
二叉树的基本概念：
	1、满足条件：
		每个节点的度都不大于二
		每个结点的孩子结点次序不能任意颠倒
	2、性质：
		在二叉树的第i层上至多有2^(i-1)个结点（i>=1)
		深度为k的二叉树至多有2^k-1个结点（k>=1)
		对任何一棵二叉树，如果其终端结点数为n0，度为2的结点数为n2，则叶子结点
		n0=n2+1
		具有n个结点的完全二叉树的深度为([log]2n)+1		(log以二为底n的对数）
		如果对一棵有n个结点的完全二叉树的结点按层序编号（从第一层到([log]2n)+1
		层，从左到右），则对任一结点i（1<=i<=n），有：
		（1）如果i=1，则结点i无双亲，是二叉树的根，如果i>1，则其双亲是结点i/2
		（2）如果2i>n，则结点i为叶子结点，无左右孩子，否则其左孩子是结点2i
		（3）如果2i+1>n，则结点i无右节点，否则其右节点为2i+1
	3、完全二叉树：
		在一棵二叉树中，除了最后一层，都是满的，并且最后一次或是满的，或是右边
		缺少连接若干结点
		（特点）：
			所有的叶结点都出现在第k层或k-1层
			取任一结点，如果其右子树的最大层为1，则其左子树的最大层次为1
	4、满二叉树：
		树中除了叶子结点，每个结点都有两个结点

二叉树的存储结构：
	顺序存储：
		二叉树的顺序存储结构中结点的存放次序是：对该树中每一个结点进行编号，其
	编号从小到大的顺序就是结点存放在连续存储单元的先后次序
*******************************************************************************/
//二叉树的链式存储结构如下：
typedef struct node {
	ElemType data;
	struct node* lchild, * rchild;
}BTNode;
//data表示值域，lchild和rchild分别存放左右子树根节点的存储位置

/*二叉树的遍历*/

//递归法：
//先序遍历
void PreOrder(Bitree T)
{
	if (T)
	{
		visit(T->data);
		PreOrder(T->lchild);
		PreOrder(t->rchild);
	}
}

//中序遍历
void MidOrder(Bitree T)
{
	if (T)
	{
		PreOrder(T->lchild);
		visit(T->data);
		PreOrder(T->rchild);
	}
}
//后序遍历
void EndOrder(Bitree T)
{
	if (T) {
		PreOrder(T -> lchild);
		PreOrder(T->rchild);
		visit(T->data);
	}
}

//非递归方法
//先序遍历
void PreOrderTraverse(BiTree T, LStack* S)
{
	InitStack(S);
	BiTree p = T;
	while (p || !Empty(S))
	{
		if (p)
		{
			visit(P->data);//输出根节点
			S->Stack[++S->top] = p;//记录父结点
			p = p->LChild;//遍历左节点
		}
		else {
			p = S->Stack[S - top--];//寻找根结点
			p = p->RChild;//遍历右结点
		}
	}
}

void MidORderTraverse(BiTree T, LStack* S)
{
	InitStack(S);
	BiTree p = T;
	while (p || !Empty(S))
	{
		if (p)
		{
			S->Stack[++S->top] = p;
			p = p->LChild;
		}
		else
		{
			p = S->Stack[S->top--];//获取根结点
			visit(p->data);
			p = p->RChild;
		}
	}
}

//后序遍历：
void ReaOrderTraverse(BiTree T, LStack* S)
{
	InitStack(S);
	BiTree p = T;
	r = NULL;
	while (p || !Empty(S))
	{
		if (p)
		{
			S->Stack[++S->top] = p;
			p = p->LChild;
		}
		else
		{
			p = S->Stack[S->top];
			if (p->Rchild && p->Rchild!r)
				p = p->RChild;
			else
			{
				--S->top;
				printf("%c", p->data);
				r = p;
				p = NULL;
			}
		}
	}
}

//二叉树层次遍历
void LevelOrder(BiTree T)
{
	InitQueue(Q);
	BiTree p;
	EnQueue(Q, T);
	while (!IsEmpty(Q))
	{
		DeQueue(Q, p);
		visit(p);
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);
	}
}

//线索二叉树
//结点结构图：
/*******************************************************************************
--------------------------------------------------------------------------------
|	lChild	|	Ltag	|	Data	|	Rtag	|	RChild	|
--------------------------------------------------------------------------------
如果有左孩子，则Lchild继续指向左孩子，否则指向该结点的前驱结点
如果有右孩子，则Rchild继续指向右孩子，否则指向该结点的后继结点
Ltadg是用来标记是左孩子(ltag=0)还是前驱结点(ltag=1)
Rtag用来标记是右孩子(Rtag=0)还是后继结点（Rtag=1）
*************************************************************/


//树和森林遍历与二叉树遍历对应关系
/********************************
---------------------------------
  树    |   森林	    |	二叉树  |
---------------------------------
先跟遍历| 先序遍历	|  先序遍历	|
---------------------------------
后跟遍历| 中序遍历	|  中序遍历	|
---------------------------------
*********************************/

//二叉树和森林之间的转换
/*
	(1)转换：将森林中没一棵树转换称二叉树
	(2)连线：将各棵树转换后的二叉树的根结点相连
	(3)旋转：将添加的水平连线和原有的连线，以第一棵树的根结点为轴按顺时针方向粗略旋转45°
*/
//二叉树还原为森林的步骤
/*
	（1）抹线：抹掉二叉树根结点右链上的所有结点上的连线，分成若干个以右链上的结点为根结点的子二叉树
	（2）转换：将分好的子二叉树转换成树
	（3）调整：将转换好的树的根结点排列成一排
*/



//求二叉树的叶子结点数
int sun = 0;
void CaculateLeafNun(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}
	if (root->lchild == NULL && root->rchild == NULL)
	{
		printf("%c\n", root->ch);
		num++;
	}
	CaculateLeafNun(root->lchild);//左子树叶子结点的数目
	CaculateLeafNun(root->rchild);//右子树叶子结点的数目
}

//求二叉树高度（深度）
int Btdopth(B1Tree T)
{
	if (!T)
		return 0;//数空，高度为0
	int front = -1, rear = -1;
	int last = 0, level = 0;//last指向当前层的最右结点
	BiTree Q[Maxsize];
	//设置队列Q，元素是叉树结点指针，且容量足够
	Q[++rear] = T;

}
