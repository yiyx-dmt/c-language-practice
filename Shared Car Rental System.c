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

void Insert();
void InsertRenter();
void InsertVehicle();
void InsertRental();

void Update();
void UpdateRenter();
void UpdateVehicle();
void UpdateRental();

void Delete();
void DeleteRenter();
void DeleteVehicle();
void DeleteRental();

void Search();
void SearchRenter();
void SearchVehicle();
void SearchRental();

void Statistics();
void StatisticsRenter();
void StatisticsVehicle();
void StatisticsRental();

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
        printf("请输入您想增加的记录表:\n");
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
    printf("编号:\n");    scanf("%d",&RenterList[rentercnt].num1);
    printf("姓名:\n");    scanf("%s",RenterList[rentercnt].name);
    printf("性别:\n");    scanf(" %c",&RenterList[rentercnt].sex);
    printf("年龄:\n");    scanf("%d",&RenterList[rentercnt].age);
    printf("职业:\n");    scanf("%s",RenterList[rentercnt].job);
    printf("电话:\n");    scanf("%s",RenterList[rentercnt].phone);
    printf("身份证号:\n");    scanf("%s",RenterList[rentercnt].id);
    printf("居住地址:\n");    scanf("%s",RenterList[rentercnt].addr);
    rentercnt++;
    printf("增加成功!\n");
}

// ============ 增加车辆信息 ============
void InsertVehicle()
{
    if(vehiclecnt == MaxSize){
        printf("空间已满！");
        return;
    }
    printf("车牌号码:\n");    scanf("%s",VehicleList[vehiclecnt].plate);
    printf("车辆品牌:\n");    scanf("%s",VehicleList[vehiclecnt].brand);
    printf("车辆类型:\n");    scanf("%s",VehicleList[vehiclecnt].type);
    printf("车身颜色:\n");    scanf("%s",VehicleList[vehiclecnt].color);
    printf("核载人数:\n");    scanf("%d",&VehicleList[vehiclecnt].seats);
    printf("租借状态:\n");    scanf(" %c",&VehicleList[vehiclecnt].isRented);
    vehiclecnt++;
    printf("增加成功!\n");
}

// ============ 增加租车登记信息 ============
void InsertRental()
{
    if(rentalcnt == MaxSize){
        printf("空间已满！");
        return;
    }
    printf("登记号:\n");    scanf("%d",&RentalList[rentalcnt].num2);
    printf("姓名:\n");    scanf("%s",RentalList[rentalcnt].name);
    printf("电话:\n");    scanf("%s",RentalList[rentalcnt].phone);
    printf("车牌号码:\n");    scanf("%s",RentalList[rentalcnt].plate);
    printf("借车日期:\n");    scanf("%s",RentalList[rentalcnt].borrow_date);
    printf("还车日期:\n");    scanf("%s",RentalList[rentalcnt].return_date);
    printf("违约情况:\n");    scanf(" %c",&RentalList[rentalcnt].isViolated);
    rentalcnt++;
    printf("增加成功!\n");
}

//============修改记录 ============
void Update()
{
    int choice;
    do{
        printf("\n");
        printf("===============修改================\n");
        printf("1---租车人信息记录表(RenterList)\n");
        printf("2---车辆信息记录表(VehicleList)\n");
        printf("3---租车登记信息记录表(RentalList)\n");
        printf("4---返回(Return)\n");
        printf("==================================\n");
        printf("请选择您想修改的记录表:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :UpdateRenter();
                    break;
            case 2 :UpdateVehicle();
                    break;
            case 3 :UpdateRental();
                    break;
            case 4 :break;
            default:printf("选择错误!请重选");break;
        }
    } while(choice != 4);
}

// ============ 修改租车人信息 ============
void UpdateRenter()
{
    int i,number,flag=1;
    printf("请输入要修改的租车人信息记录表编号:");
    scanf("%d",&number);
    for(i = 0; i<rentercnt && flag;i++){
        if(RenterList[i].num1 == number){
            printf("请输入姓名:\n");    
            scanf("%s",RenterList[i].name);
            printf("请输入性别:\n");    
            scanf(" %c",&RenterList[i].sex);
            printf("请输入年龄:\n");    
            scanf("%d",&RenterList[i].age);
            printf("请输入职业:\n");    
            scanf("%s",RenterList[i].job);
            printf("请输入电话:\n");    
            scanf("%s",RenterList[i].phone);
            printf("请输入身份证号:\n");
            scanf("%s",RenterList[i].id);
            printf("请输入居住地址:\n");    
            scanf("%s",RenterList[i].addr);
            flag = 0;
        }
    }
    if(flag == 0){
        printf("修改成功!\n");
    }else{
        printf("没有查询到可以修改的数据!\n");
    }
}

// ============ 修改车辆信息 ============
void UpdateVehicle()
{
    int i,flag=1;
    char p[20];
    printf("请输入要修改的车辆信息记录表车牌号:");
    scanf("%s",p);
    for(i = 0; i<vehiclecnt && flag;i++){
        if(strcmp(VehicleList[i].plate,p) == 0){
            printf("请输入车辆品牌:\n");    
            scanf("%s",VehicleList[i].brand);
            printf("请输入车辆类型:\n");    
            scanf("%s",VehicleList[i].type);
            printf("请输入车身颜色:\n");    
            scanf("%s",VehicleList[i].color);
            printf("请输入核载人数:\n");    
            scanf("%d",&VehicleList[i].seats);
            printf("请输入租借状态:\n");
            scanf(" %c",&VehicleList[i].isRented);
            flag = 0;
        }
    }
    if(flag == 0){
        printf("修改成功!\n");
    }else{
        printf("没有查询到可以修改的数据!\n");
    }
}

// ============ 修改租车登记信息 ============
void UpdateRental()
{
    int i,number,flag=1;
    printf("请输入要修改的租车登记信息记录表编号:");
    scanf("%d",&number);
    for(i = 0; i<rentalcnt && flag;i++){
        if(RentalList[i].num2 == number){
            printf("请输入姓名:\n");    
            scanf("%s",RentalList[i].name);
            printf("请输入电话:\n");    
            scanf("%s",RentalList[i].phone);
            printf("请输入车牌号码:\n");    
            scanf("%s",RentalList[i].plate);
            printf("请输入借车日期:\n");    
            scanf("%s",RentalList[i].borrow_date);
            printf("请输入还车日期:\n");    
            scanf("%s",RentalList[i].return_date);
            printf("请输入违约情况:\n");
            scanf(" %c",&RentalList[i].isViolated);
            flag = 0;
        }
    }
    if(flag == 0){
        printf("修改成功!\n");
    }else{
        printf("没有查询到可以修改的数据!\n");
    }
}

//============ 删除记录 ============
void Delete()
{
    int choice;
    do{
        printf("\n");
        printf("===============删除================\n");
        printf("1---租车人信息记录表(RenterList)\n");
        printf("2---车辆信息记录表(VehicleList)\n");
        printf("3---租车登记信息记录表(RentalList)\n");
        printf("4---返回(Return)\n");
        printf("==================================\n");
        printf("请选择您想删除的记录表:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :DeleteRenter();
                    break;
            case 2 :DeleteVehicle();
                    break;
            case 3 :DeleteRental();
                    break;
            case 4 :break;
            default:printf("选择错误!请重选");break;
        }
    } while(choice != 4);
}

// ============ 删除租车人信息 ============
void DeleteRenter()
{
    int i,j,number,flag=1;
    int choice;
    char n[20];
    printf("1按编号删除,2按姓名删除,请输入数字:\n");
    scanf("%d",&choice);
    if(choice == 1){
        printf("请输入要删除的租车人信息记录表编号:");
        scanf("%d",&number);
        for(i = 0; i<rentercnt && flag;i++){
            if(RenterList[i].num1 == number){
                printf("将删除以下租车人信息:\n");
                printf("编号:%d 姓名:%s 性别:%c 年龄:%d 职业:%s 电话:%s 身份证:%s 地址:%s\n",RenterList[i].num1, RenterList[i].name, RenterList[i].sex,RenterList[i].age, RenterList[i].job, RenterList[i].phone,RenterList[i].id,RenterList[i].addr);
                for(j = i;j <rentercnt - 1;j++){
                    RenterList[j] = RenterList[j+1];
                }
                flag = 0;
                rentercnt--;
            }
        }
    }else if(choice == 2){
        printf("请输入要删除的租车人信息记录表姓名:\n");
        scanf("%s",n);
        for(i = 0; i<rentercnt && flag;i++){
            if(strcmp(RenterList[i].name,n) == 0){
                printf("将删除以下租车人信息:\n");
                printf("编号:%d 姓名:%s 性别:%c 年龄:%d 职业:%s 电话:%s 身份证:%s 地址:%s\n",RenterList[i].num1, RenterList[i].name, RenterList[i].sex,RenterList[i].age, RenterList[i].job, RenterList[i].phone,RenterList[i].id,RenterList[i].addr);
                for(j = i;j <rentercnt - 1;j++){
                    RenterList[j] = RenterList[j+1];
                }
                flag = 0;
                rentercnt--;
            }
        }
    }
    if(flag == 0){
        printf("删除成功!\n");
    }else{
        printf("没有查询到可以删除的数据!\n");
    }
}

// ============ 删除车辆信息 ============
void DeleteVehicle()
{
    int i,j,flag=1;
    char p[20];
    printf("请输入要删除的车辆信息记录表编号:");
    scanf("%s",p);
    for(i = 0; i<vehiclecnt && flag;i++){
        if(strcmp(VehicleList[i].plate,p) == 0){
            printf("将删除以下车辆信息:\n");
            printf("车牌号码:%s 车辆品牌:%s 车辆类型:%s 车身颜色:%s 核载人数:%d 租借状态:%c\n",VehicleList[i].plate, VehicleList[i].brand, VehicleList[i].type,VehicleList[i].color,VehicleList[i].seats, VehicleList[i].isRented);
            for(j = i;j <vehiclecnt - 1;j++){
                VehicleList[j] = VehicleList[j+1];
            }
            flag = 0;
            vehiclecnt--;
        }
    }
    if(flag == 0){
        printf("删除成功!\n");
    }else{
        printf("没有查询到可以删除的数据!\n");
    }
}

// ============删除租车登记信息 ============
void DeleteRental()
{
    int i,j,number,flag=1;
    char n[20];
    int choice;
    printf("1按登记号删除,2按姓名删除,请输入数字:\n");
    scanf("%d",&choice);
    if(choice == 1){
        printf("请输入要删除的租车登记信息记录表编号:");
        scanf("%d",&number);
        for(i = 0; i<rentalcnt && flag;i++){
            if(RentalList[i].num2 == number){
                printf("将删除以下租车登记信息:\n");
                printf("登记号:%d 姓名:%s 电话:%s 车牌号码:%s 借车日期:%s 还车日期:%s 违约情况:%c\n",RentalList[i].num2, RentalList[i].name, RentalList[i].phone,RentalList[i].plate, RentalList[i].borrow_date, RentalList[i].return_date,RentalList[i].isViolated);
                for(j = i;j <rentalcnt - 1;j++){
                    RentalList[j] = RentalList[j+1];
                }
                flag = 0;
                rentalcnt--;
            }
        }
    }else if(choice == 2){
        printf("请输入要删除的租车登记信息记录表姓名:\n");
        scanf("%s",n);
        for(i = 0; i<rentalcnt && flag;i++){
            if(strcmp(RentalList[i].name,n) == 0){
                printf("将删除以下租车登记信息:\n");
                printf("登记号:%d 姓名:%s 电话:%s 车牌号码:%s 借车日期:%s 还车日期:%s 违约情况:%c\n",RentalList[i].num2, RentalList[i].name, RentalList[i].phone,RentalList[i].plate, RentalList[i].borrow_date, RentalList[i].return_date,RentalList[i].isViolated);
                for(j = i;j <rentalcnt - 1;j++){
                    RentalList[j] = RentalList[j+1];
                }
                flag = 0;
                rentalcnt--;
            }
        }
    }
    if(flag == 0){
        printf("删除成功!\n");
    }else{
        printf("没有查询到可以删除的数据!\n");
    }
}

//============ 查询记录 ============
void Search()
{
    int choice;
    do{
        printf("\n");
        printf("===============查询================\n");
        printf("1---租车人信息记录表(RenterList)\n");
        printf("2---车辆信息记录表(VehicleList)\n");
        printf("3---租车登记信息记录表(RentalList)\n");
        printf("4---返回(Return)\n");
        printf("==================================\n");
        printf("请选择您想查询的记录表:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :SearchRenter();
                    break;
            case 2 :SearchVehicle();
                    break;
            case 3 :SearchRental();
                    break;
            case 4 :break;
            default:printf("选择错误!请重选");break;
        }
    } while(choice != 4);
}

// ============ 查询租车人信息 ============
void SearchRenter()
{
    int i,found=0;         //防止同名同姓
    char n[20];
    printf("请输入要查询的租车人信息记录表姓名:\n");
    scanf("%s",n);
    for(i = 0; i < rentercnt;i++){
        if(strcmp(RenterList[i].name,n) == 0){
            printf("编号:%d\n姓名:%s\n性别:%c\n年龄:%d\n职业:%s\n电话:%s\n身份证:%s\n地址:%s\n",RenterList[i].num1, RenterList[i].name, RenterList[i].sex,RenterList[i].age, RenterList[i].job, RenterList[i].phone,RenterList[i].id,RenterList[i].addr);
            found++;
        }
    }
    if(found != 0){
        printf("查询成功!\n");
    }else{
        printf("没有查询到!\n");
    }
}

// ============ 查询车辆信息 ============
void SearchVehicle()
{
    int i,choice,found=0;
    char b[20];
    char r;
    printf("1按车辆品牌查询,2按租借状态查询,请输入数字:\n");
    scanf("%d",&choice);
    if(choice == 1){
        printf("请输入要查询的车辆信息记录表品牌:\n");
        scanf("%s",b);
        for(i = 0; i < vehiclecnt;i++){
            if(strcmp(VehicleList[i].brand,b) == 0){
                printf("车牌号码:%s\n车辆品牌:%s\n车辆类型:%s\n车身颜色:%s\n核载人数:%d\n租借状态:%c\n",VehicleList[i].plate, VehicleList[i].brand, VehicleList[i].type,VehicleList[i].color,VehicleList[i].seats, VehicleList[i].isRented);
                found++;
            }
        }
    }else if(choice == 2){
        printf("请输入要查询的车辆信息记录表租借状态(Y/N):\n");
        scanf(" %c",&r);
        for(i = 0; i < vehiclecnt;i++){
            if(VehicleList[i].isRented == r){
                printf("车牌号码:%s\n车辆品牌:%s\n车辆类型:%s\n车身颜色:%s\n核载人数:%d\n租借状态:%c\n",VehicleList[i].plate, VehicleList[i].brand, VehicleList[i].type,VehicleList[i].color,VehicleList[i].seats, VehicleList[i].isRented);
                found++;
            }
        }
    }
    if(found != 0){
        printf("查询成功!\n");
    }else{
        printf("没有查询到!\n");
    }
}

// ============查询租车登记信息 ============
void SearchRental()
{
    int i,choice,found=0;        //防止同名同姓
    char n[20];
    char p[20];
    printf("1按车牌号码查询,2按姓名查询,请输入数字:\n");
    scanf("%d",&choice);
    if(choice == 1){
        printf("请输入要查询的租车登记信息记录表车牌号码:\n");
        scanf("%s",p);
        for(i = 0; i < rentalcnt;i++){
            if(strcmp(RentalList[i].plate,p) == 0){
                printf("登记号:%d\n姓名:%s\n电话:%s\n车牌号码:%s\n借车日期:%s\n还车日期:%s\n违约情况:%c\n",RentalList[i].num2, RentalList[i].name, RentalList[i].phone,RentalList[i].plate, RentalList[i].borrow_date, RentalList[i].return_date,RentalList[i].isViolated);
                found++;
            }
        }
    }else if(choice == 2){
        printf("请输入要查询的租车登记信息记录表姓名:\n");
        scanf("%s",n);
        for(i = 0; i < rentalcnt;i++){
            if(strcmp(RentalList[i].name,n) == 0){
                printf("登记号:%d\n姓名:%s\n电话:%s\n车牌号码:%s\n借车日期:%s\n还车日期:%s\n违约情况:%c\n",RentalList[i].num2, RentalList[i].name, RentalList[i].phone,RentalList[i].plate, RentalList[i].borrow_date, RentalList[i].return_date,RentalList[i].isViolated);
                found++;
            }
        }
    }
    if(found != 0){
        printf("查询成功!\n");
    }else{
        printf("没有查询到!\n");
    }
}