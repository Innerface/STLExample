#include "pch.h"
#include "mysql_demo.h"

MYSQL mysql; //mysql连接
MYSQL_FIELD *fd;  //字段列数组
char field[32][32];  //存字段名二维数组
MYSQL_RES *res; //这个结构代表返回行的一个查询结果集
MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列
char query[150]; //查询语句

MysqlDemo::MysqlDemo()
{
}

MysqlDemo::~MysqlDemo()
{
}

//连接数据库
bool MysqlDemo::ConnectDatabase()
{
	//初始化mysql
	mysql_init(&mysql);  //连接mysql，数据库

	//返回false则连接失败，返回true则连接成功
	if (!(mysql_real_connect(&mysql, "localhost", "yuyue", "yuyue", "space", 0, NULL, 0))) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去
	{
		printf("Error connecting to database:%s\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Connected...\n");
		return true;
	}
}

//释放资源
void MysqlDemo::FreeConnect()
{
	//释放资源
	mysql_free_result(res);
	mysql_close(&mysql);
}

//其实所有的数据库操作都是先写个sql语句，然后用mysql_query(&mysql,query)来完成，包括创建数据库或表，增删改查
//查询数据
bool MysqlDemo::QueryDatabase1()
{
	sprintf(query, "select * from wechat_user"); //执行查询语句，这里是查询所有，user是表名，不用加引号，用strcpy也可以
	mysql_query(&mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码
	//返回0 查询成功，返回1查询失败
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("query success\n");
	}
	//获取结果集
	if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
	{
		printf("Couldn't get result from %s\n", mysql_error(&mysql));
		return false;
	}

	//打印数据行数
	printf("number of dataline returned: %d\n", mysql_affected_rows(&mysql));

	//获取字段的信息
	char *str_field[32];  //定义一个字符串数组存储字段信息
	for (int i = 0; i < 4; i++)   //在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;
	}
	for (int i = 0; i < 4; i++)   //打印字段
		printf("%10s\t", str_field[i]);
	printf("\n");
	//打印获取的数据
	while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
	{
		printf("%10s\t%10s\t%10s\t%10s\n", column[0], column[1], column[2], column[3]);  //column是列数组
	}
	return true;
}

bool MysqlDemo::QueryDatabase2()
{
	mysql_query(&mysql, "set names gbk");
	//返回0 查询成功，返回1查询失败
	if (mysql_query(&mysql, "select * from wechat_user"))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("query success\n");
	}
	res = mysql_store_result(&mysql);
	//打印数据行数
	printf("number of dataline returned: %d\n", mysql_affected_rows(&mysql));
	for (int i = 0; fd = mysql_fetch_field(res); i++)  //获取字段名
		strcpy(field[i], fd->name);
	int j = mysql_num_fields(res);  // 获取列数
	for (int i = 0; i < j; i++)  //打印字段
		printf("%10s\t", field[i]);
	printf("\n");
	while (column = mysql_fetch_row(res))
	{
		for (int i = 0; i < j; i++)
			printf("%10s\t", column[i]);
		printf("\n");
	}
	return true;
}

//插入数据
bool MysqlDemo::InsertData()
{
	sprintf(query, "insert into wechat_user ('nickname','country','province','city') values ('Lilei', 'CHINA','GUANGZHOU','SHENZHEN');");  //可以想办法实现手动在控制台手动输入指令
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Insert success\n");
		return true;
	}
}

//修改数据
bool MysqlDemo::ModifyData()
{
	sprintf(query, "update wechat_user set city='CITY' where nickname='YuYuE'");
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Insert success\n");
		return true;
	}
}

//删除数据
bool MysqlDemo::DeleteData()
{
	/*sprintf(query, "delete from user where id=6");*/
	char query[100];
	printf("please input the sql:\n");
	gets_s(query);  //这里手动输入sql语句
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Insert success\n");
		return true;
	}
}