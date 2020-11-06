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
  返回值：无*/
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
	p = GetElemP(L, i - 1);					//在L中确定第i个元素前驱的位置指针p
	if (!P)									//p=null，即第i个元素前驱不存在（设头结点为第1个元素的前驱）
		return ERROR;
		s = (DulinkList)malloc(sizeof(DuLNode));
		if (!s)
			return OVERFLOW;
		s->data = e;
		s->prior = p;						//在第i-1个元素之后插入
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
****************************************************************************************** |
*p->next->prior=s;	|p->prior->next=s;	|s=p->next;	   |			   |
*s->next=p->next;	|s->prior=p->prior;	|p->next=s->next;  |p->prior->next=p->next;|	
*p->next=s;		|s->next=p;		|p->next->prior=p; |p->next->prior=p->prior; |
*s->prior=p;		|p->next=s;		|		   |	  		   |
*******************************************************************************************
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
思路：插入运算十将值为x的新结点插入到表的第i个节
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
队列：是一种特殊的线性表，他只允许在表的前端（front）
进行操作，而表的后端（rear)进行插入操作，和栈一样，队
列是一种操作受限制的线性表，进行插入操作的端为队尾，
进行删除操作的端称为对头。
队头（Front）：允许删除的一端，又称队首
队尾（Rear）：允许插入的一端
空队列：不含任何元素的空表
----------------------------------------------------
对列常见的操作：
	InitQueue(&Q):初始化队列
	QueueEmpty(Q):判断对空
	EnQueu(&Q,x):入队，若队列Q未满，将x加入，使之成为新的队尾
	DeQueue（&Q，&x）出队，若队列Q未空，则将队头元素删除，并用x返回
	GetHead（Q，&x）读取对头元素，若队列Q未空，则将对头元素赋值给x
***************************************************/
