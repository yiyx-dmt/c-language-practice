#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxSize 100

int rentercnt = 0;          //已登记租车人个数
int vehiclecnt = 0;         //已登记车辆个数
int rentalcnt = 0;          //已登记租车记录个数

struct Renter
{
    int num1;               //编号
    char name[20];          //姓名
    char sex;               //性别
    int age;                //年龄
    char job[20];           //职业
    char phone[15];         //电话
    char id[20];            //身份证号
    char addr[100];         //居住地址
}RenterList[MaxSize];

struct Vehicle
{
    char plate[20];         //车牌号码
    char brand[20];         //车辆品牌
    char type[20];          //车辆类型
    char color[10];         //车身颜色
    int seats;              //核载人数
    char isRented;          //租借状态
}VehicleList[MaxSize];

struct Rental
{
    int num2;               //登记号
    char name[20];          //姓名
    char phone[15];         //电话
    char plate[20];         //车牌号码
    char borrow_date[20];   //借车日期
    char return_date[20];   //还车日期
    char isViolated;        //违约情况 
}RentalList[MaxSize];

void InsertRenter();
void InsertVehicle();
void InsertRental();
void Insert();

int main()
{
    int i;
    do{
        printf("\n");
        printf("=====Shared Car Rental System=====\n");
        printf("1---增加(Insert)\n");
        printf("2---修改(Update)\n");
        printf("3---删除(Delete)\n");
        printf("4---查询(Search)\n");
        printf("5---统计(Statistics)\n");
        printf("6---退出(Exit)\n");
        printf("==================================\n");
        printf("请输入数字:\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1 :Insert();
                    break;
            case 2 :Update();
                    break;
            case 3 :Delete();
                    break;
            case 4 :Search();
                    break;
            case 5 :Statistics();
                    break;
            case 6 :break;
            default:printf("选择错误!请重选");break;
        }
    } while(i != 6);
    return 0;
}

//============ 增加记录 ============
void Insert()
{
    int choice;
    do{
        printf("\n");
        printf("===============增加================\n");
        printf("1---租车人信息记录表(RenterList)\n");
        printf("2---车辆信息记录表(VehicleList)\n");
        printf("3---租车登记信息记录表(RentalList)\n");
        printf("4---返回(Return)\n");
        printf("==================================\n");
        printf("请输入数字:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :InsertRenter();
                    break;
            case 2 :InsertVehicle();
                    break;
            case 3 :InsertRental();
                    break;
            case 4 :break;
            default:printf("选择错误!请重选");break;
        }
    } while(choice != 4);
}

// ============ 增加租车人信息 ============
void InsertRenter()
{
    if(rentercnt == MaxSize){
        printf("空间已满！");
        return;
    }
    printf("编号:");    scanf("%d",RenterList[rentercnt].num1);
    printf("姓名:");    scanf("%s",RenterList[rentercnt].name);
    printf("性别:");    scanf("%c",RenterList[rentercnt].sex);
    printf("年龄:");    scanf("%d",RenterList[rentercnt].age);
    printf("职业:");    scanf("%s",RenterList[rentercnt].job);
    printf("电话:");    scanf("%s",RenterList[rentercnt].phone);
    printf("身份证号:");    scanf("%s",RenterList[rentercnt].id);
    printf("居住地址:");    scanf("%s",RenterList[rentercnt].addr);
    rentercnt++;
    printf("增加成功!\n");
}

// ============ 增加车辆信息 ============
void InsertRenter()
{
    if(rentercnt == MaxSize){
        printf("空间已满！");
        return;
    }
    printf("车牌号码:");    scanf("%d",RenterList[rentercnt].num1);
    printf("车辆品牌:");    scanf("%s",RenterList[rentercnt].name);
    printf("车辆类型:");    scanf("%c",RenterList[rentercnt].sex);
    printf("车身颜色:");    scanf("%d",RenterList[rentercnt].age);
    printf("核载人数:");    scanf("%s",RenterList[rentercnt].job);
    printf("租借状态:");    scanf("%s",RenterList[rentercnt].phone);
    vehiclecnt++;
    printf("增加成功!\n");
}

// ============ 增加租车登记信息 ============
void InsertRenter()
{
    if(rentercnt == MaxSize){
        printf("空间已满！");
        return;
    }
    printf("登记号:");    scanf("%d",RenterList[rentercnt].num1);
    printf("姓名:");    scanf("%s",RenterList[rentercnt].name);
    printf("电话:");    scanf("%s",RenterList[rentercnt].phone);
    rentalcnt++;
    printf("增加成功!\n");
}