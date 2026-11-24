#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
    struct Renter *next;    //指向下一个结点
};

struct Vehicle
{
    char plate[20];         //车牌号码
    char brand[20];         //车辆品牌
    char type[20];          //车辆类型
    char color[10];         //车身颜色
    int seats;              //核载人数
    char isRented;          //租借状态
    struct Vehicle *next;   //指向下一个结点
};

struct Rental
{
    int num2;               //登记号
    char name[20];          //姓名
    char phone[15];         //电话
    char plate[20];         //车牌号码
    char borrow_date[20];   //借车日期
    char return_date[20];   //还车日期
    char isViolated;        //违约情况
    struct Rental *next;    //指向下一个结点
};

struct Renter  *renterHead  = NULL;     //三个头指针
struct Vehicle *vehicleHead = NULL;
struct Rental  *rentalHead  = NULL;

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
void StatisticsRentalCnt();        //统计某人租车次数
void StatisticsViolationCnt();     //统计某人违约次数

int checkPhone(char p[]);          //保证电话号码由11位数字组成

void LoadData();                   //启动时读文件
void SaveData();                   //退出前写文件

int main()
{
    int i;
    LoadData();
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
            default:printf("选择错误!请重选。\n");break;
        }
    } while(i != 6);
    SaveData();
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
        printf("请输入您想增加的记录表:");
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
            default:printf("选择错误!请重选。\n");break;
        }
    } while(choice != 4);
}

// ============ 增加租车人信息 ============
void InsertRenter()
{
    struct Renter *p = (struct Renter*)malloc(sizeof(struct Renter));
    struct Renter *tail;
    if(p == NULL){
        printf("内存不足!\n");
        return;
    }
    printf("编号:\n");    scanf("%d",&p->num1);
    printf("姓名:\n");    scanf("%s",p->name);
    printf("性别:\n");    scanf(" %c",&p->sex);
    printf("年龄:\n");    scanf("%d",&p->age);
    printf("职业:\n");    scanf("%s",p->job);
    do{
        printf("电话:\n");
        scanf("%s",p->phone);
        if(checkPhone(p->phone) == 0){
            printf("电话必须是11位数字,请重新输入!\n");
        }
    }while(checkPhone(p->phone) == 0);
    printf("身份证号:\n");    scanf("%s",p->id);
    printf("居住地址:\n");    scanf("%s",p->addr);
    
    p->next = NULL;
    if(renterHead == NULL){
        renterHead = p;
    }else{
        tail = renterHead;
        while(tail->next != NULL) tail = tail->next;
        tail->next = p;
    }
    rentercnt++;
    printf("增加成功!\n");
}

// ============ 增加车辆信息 ============
void InsertVehicle()
{
    struct Vehicle *p = (struct Vehicle*)malloc(sizeof(struct Vehicle));
    struct Vehicle *tail;
    if(p == NULL){
        printf("内存不足!\n");
        return;
    }
    printf("车牌号码:\n");    scanf("%s",p->plate);
    printf("车辆品牌:\n");    scanf("%s",p->brand);
    printf("车辆类型:\n");    scanf("%s",p->type);
    printf("车身颜色:\n");    scanf("%s",p->color);
    printf("核载人数:\n");    scanf("%d",&p->seats);
    printf("租借状态:\n");    scanf(" %c",&p->isRented);

    p->next = NULL;
    if(vehicleHead == NULL){
        vehicleHead = p;
    }else{
        tail = vehicleHead;
        while(tail->next != NULL) tail = tail->next;
        tail->next = p;
    }
    vehiclecnt++;
    printf("增加成功!\n");
}

// ============ 增加租车登记信息 ============
void InsertRental()
{
    struct Rental *p = (struct Rental*)malloc(sizeof(struct Rental));
    struct Rental *tail;
    if(p == NULL){
        printf("内存不足!\n");
        return;
    }
    printf("登记号:\n");    scanf("%d",&p->num2);
    printf("姓名:\n");      scanf("%s",p->name);
    do{
        printf("电话:\n");
        scanf("%s",p->phone);
        if(checkPhone(p->phone) == 0){
            printf("电话必须是11位数字,请重新输入!\n");
        }
    }while(checkPhone(p->phone) == 0);
    printf("车牌号码:\n");    scanf("%s",p->plate);
    printf("借车日期:\n");    scanf("%s",p->borrow_date);
    printf("还车日期:\n");    scanf("%s",p->return_date);
    printf("违约情况:\n");    scanf(" %c",&p->isViolated);

    p->next = NULL;
    if(rentalHead == NULL){
        rentalHead = p;
    }else{
        tail = rentalHead;
        while(tail->next != NULL) tail = tail->next;
        tail->next = p;
    }
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
        printf("请选择您想修改的记录表:");
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
            default:printf("选择错误!请重选。\n");break;
        }
    } while(choice != 4);
}

// ============ 修改租车人信息 ============
void UpdateRenter()
{
    int number;
    struct Renter *p = renterHead;
    printf("请输入要修改的租车人信息记录表编号:");
    scanf("%d",&number);

    while(p != NULL){
        if(p->num1 == number){
            printf("请输入姓名:\n");    
            scanf("%s",p->name);
            printf("请输入性别:\n");    
            scanf(" %c",&p->sex);
            printf("请输入年龄:\n");    
            scanf("%d",&p->age);
            printf("请输入职业:\n");    
            scanf("%s",p->job);
            do{
            printf("请输入电话:\n");
            scanf("%s",p->phone);
            if(checkPhone(p->phone) == 0){
                printf("电话必须是11位数字,请重新输入!\n");
            }
        }while(checkPhone(p->phone) == 0);
            printf("请输入身份证号:\n");
            scanf("%s",p->id);
            printf("请输入居住地址:\n");    
            scanf("%s",p->addr);
            return;
        }
        p = p->next;
    }
    printf("没有查询到可以修改的数据!\n");
}

// ============ 修改车辆信息 ============
void UpdateVehicle()
{
    char plate[20];
    struct Vehicle *p = vehicleHead;
    printf("请输入要修改的车辆信息记录表车牌号:");
    scanf("%s",plate);

    while(p != NULL){
        if(strcmp(p->plate,plate) == 0){
            printf("请输入车辆品牌:\n");    
            scanf("%s",p->brand);
            printf("请输入车辆类型:\n");    
            scanf("%s",p->type);
            printf("请输入车身颜色:\n");    
            scanf("%s",p->color);
            printf("请输入核载人数:\n");    
            scanf("%d",&p->seats);
            printf("请输入租借状态:\n");
            scanf(" %c",&p->isRented);
            return;
        }
        p = p->next;
    }
    printf("没有查询到可以修改的数据!\n");
}

// ============ 修改租车登记信息 ============
void UpdateRental()
{
    int number;
    struct Rental *p = rentalHead;
    printf("请输入要修改的租车登记信息记录表编号:");
    scanf("%d",&number);

    while(p != NULL){
        if(p->num2 == number){
            printf("请输入姓名:\n");    
            scanf("%s",p->name);
            do{
            printf("请输入电话:\n");
            scanf("%s",p->phone);
            if(checkPhone(p->phone) == 0){
                printf("电话必须是11位数字,请重新输入!\n");
            }
        }while(checkPhone(p->phone) == 0);
            printf("请输入车牌号码:\n");    
            scanf("%s",p->plate);
            printf("请输入借车日期:\n");    
            scanf("%s",p->borrow_date);
            printf("请输入还车日期:\n");    
            scanf("%s",p->return_date);
            printf("请输入违约情况:\n");
            scanf(" %c",&p->isViolated);
            return;
        }
        p = p->next;
    }
    printf("没有查询到可以修改的数据!\n");
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
        printf("请选择您想删除的记录表:");
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
            default:printf("选择错误!请重选。\n");break;
        }
    } while(choice != 4);
}

// ============ 删除租车人信息 ============
void DeleteRenter()
{
    int number;
    int choice;
    char n[20];
    struct Renter *p = renterHead;
    struct Renter *prev = NULL;
    printf("1按编号删除,2按姓名删除,请输入数字:");
    scanf("%d",&choice);

    if(choice == 1){
        printf("请输入要删除的租车人信息记录表编号:");
        scanf("%d",&number);
        while(p != NULL){
            if(p->num1 == number){
                printf("将删除以下租车人信息:\n");
                printf("编号:%d 姓名:%s 性别:%c 年龄:%d 职业:%s 电话:%s 身份证:%s 地址:%s\n",p->num1,p->name,p->sex,p->age,p->job,p->phone,p->id,p->addr);
                if(prev == NULL){
                    renterHead = p->next;
                }else{
                    prev->next = p->next;
                }
                free(p);
                rentercnt--;
                printf("删除成功!\n");
                return;
            }
            prev = p;
            p = p->next;
        }
        printf("没有查询到可以删除的数据!\n");
    }else if(choice == 2){
        printf("请输入要删除的租车人信息记录表姓名:");
        scanf("%s",n);
        while(p != NULL){
            if(strcmp(p->name,n) == 0){
                printf("将删除以下租车人信息:\n");
                printf("编号:%d 姓名:%s 性别:%c 年龄:%d 职业:%s 电话:%s 身份证:%s 地址:%s\n",p->num1,p->name,p->sex,p->age,p->job,p->phone,p->id,p->addr);
                if(prev == NULL){
                    renterHead = p->next;
                }else{
                    prev->next = p->next;
                }
                free(p);
                rentercnt--;
                printf("删除成功!\n");
                return;
            }
            prev = p;
            p = p->next;
        }
        printf("没有查询到可以删除的数据!\n");
    }
}

// ============ 删除车辆信息 ============
void DeleteVehicle()
{
    struct Vehicle *p = vehicleHead;
    struct Vehicle *prev = NULL;
    char plate[20];
    printf("请输入要删除的车辆信息记录表车牌号码:");
    scanf("%s",plate);

    while(p != NULL){
        if(strcmp(p->plate,plate) == 0){
            printf("将删除以下车辆信息:\n");
            printf("车牌号码:%s 车辆品牌:%s 车辆类型:%s 车身颜色:%s 核载人数:%d 租借状态:%c\n",p->plate,p->brand,p->type,p->color,p->seats,p->isRented);
            if(prev == NULL){
                vehicleHead = p->next;
            }else{
                prev->next = p->next;
            }
            free(p);
            vehiclecnt--;
            printf("删除成功!\n");
            return;
        }
        prev = p;
        p = p->next;
    }
    printf("没有查询到可以删除的数据!\n");
}

// ============删除租车登记信息 ============
void DeleteRental()
{
    int number;
    char n[20];
    int choice;
    struct Rental *p = rentalHead;
    struct Rental *prev = NULL;
    printf("1按登记号删除,2按姓名删除,请输入数字:");
    scanf("%d",&choice);
    if(choice == 1){
        printf("请输入要删除的租车登记信息记录表编号:");
        scanf("%d",&number);

        while(p != NULL){
            if(p->num2 == number){
                printf("将删除以下租车登记信息:\n");
                printf("登记号:%d 姓名:%s 电话:%s 车牌号码:%s 借车日期:%s 还车日期:%s 违约情况:%c\n",p->num2,p->name,p->phone,p->plate,p->borrow_date,p->return_date,p->isViolated);
                if(prev == NULL){
                    rentalHead = p->next;
                }else{
                    prev->next = p->next;
                }
                free(p);
                rentalcnt--;
                printf("删除成功!\n");
                return;
            }
            prev = p;
            p = p->next;
        }
        printf("没有查询到可以删除的数据!\n");
    }else if(choice == 2){
        printf("请输入要删除的租车登记信息记录表姓名:");
        scanf("%s",n);
        while(p != NULL){
            if(strcmp(p->name,n) == 0){
                printf("将删除以下租车登记信息:\n");
                printf("登记号:%d 姓名:%s 电话:%s 车牌号码:%s 借车日期:%s 还车日期:%s 违约情况:%c\n",p->num2,p->name,p->phone,p->plate,p->borrow_date,p->return_date,p->isViolated);
                if(prev == NULL){
                    rentalHead = p->next;
                }else{
                    prev->next = p->next;
                }
                free(p);
                rentalcnt--;
                printf("删除成功!\n");
                return;
            }
            prev = p;
            p = p->next;
        }
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
        printf("请选择您想查询的记录表:");
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
            default:printf("选择错误!请重选。\n");break;
        }
    } while(choice != 4);
}

// ============ 查询租车人信息 ============
void SearchRenter()
{
    int found=0;
    char n[20];
    struct Renter *p = renterHead;
    printf("请输入要查询的租车人信息记录表姓名:");
    scanf("%s",n);
    while(p != NULL){               //可能出现同名同姓
        if(strcmp(p->name,n) == 0){
            printf("编号:%d\n姓名:%s\n性别:%c\n年龄:%d\n职业:%s\n电话:%s\n身份证:%s\n地址:%s\n",p->num1,p->name,p->sex,p->age,p->job,p->phone,p->id,p->addr);
            found++;
        }
        p = p->next;
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
    int choice,found=0;
    char b[20];
    char r;
    struct Vehicle *p = vehicleHead;
    printf("1按车辆品牌查询,2按租借状态查询,请输入数字:");
    scanf("%d",&choice);
    if(choice == 1){
        printf("请输入要查询的车辆信息记录表品牌:");
        scanf("%s",b);
        while(p != NULL){
            if(strcmp(p->brand,b) == 0){
                printf("车牌号码:%s\n车辆品牌:%s\n车辆类型:%s\n车身颜色:%s\n核载人数:%d\n租借状态:%c\n",p->plate,p->brand,p->type,p->color,p->seats,p->isRented);
                found++;
            }
            p = p->next;
        }
    }else if(choice == 2){
        printf("请输入要查询的车辆信息记录表租借状态(Y/N):");
        scanf(" %c",&r);
        while(p != NULL){
            if(p->isRented == r){
                printf("车牌号码:%s\n车辆品牌:%s\n车辆类型:%s\n车身颜色:%s\n核载人数:%d\n租借状态:%c\n",p->plate,p->brand,p->type,p->color,p->seats,p->isRented);
                found++;
            }
            p = p->next;
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
    int choice,found=0;
    char n[20];
    char plate[20];
    struct Rental *p = rentalHead;
    printf("1按车牌号码查询,2按姓名查询,请输入数字:");
    scanf("%d",&choice);
    if(choice == 1){
        printf("请输入要查询的租车登记信息记录表车牌号码:");
        scanf("%s",plate);
        while(p != NULL){
            if(strcmp(p->plate,plate) == 0){
                printf("登记号:%d\n姓名:%s\n电话:%s\n车牌号码:%s\n借车日期:%s\n还车日期:%s\n违约情况:%c\n",p->num2,p->name,p->phone,p->plate,p->borrow_date,p->return_date,p->isViolated);
                found++;
            }
            p = p->next;
        }
    }else if(choice == 2){
        printf("请输入要查询的租车登记信息记录表姓名:\n");
        scanf("%s",n);
        while(p != NULL){               //可能出现同名同姓
            if(strcmp(p->name,n) == 0){
                printf("登记号:%d\n姓名:%s\n电话:%s\n车牌号码:%s\n借车日期:%s\n还车日期:%s\n违约情况:%c\n",p->num2,p->name,p->phone,p->plate,p->borrow_date,p->return_date,p->isViolated);
                found++;
            }
            p = p->next;
        }
    }
    if(found != 0){
        printf("查询成功!\n");
    }else{
        printf("没有查询到!\n");
    }
}

//============ 统计记录 ============
void Statistics()
{
    int choice;
    do{
        printf("\n");
        printf("===============统计================\n");
        printf("1---租车次数统计表(RentercntList)\n");
        printf("2---违约次数统计表(ViolationcntList)\n");
        printf("3---返回(Return)\n");
        printf("==================================\n");
        printf("请选择您想查看的统计表:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :StatisticsRentalCnt();
                    break;
            case 2 :StatisticsViolationCnt();
                    break;
            case 3 :break;
            default:printf("选择错误!请重选。\n");break;
        }
    } while(choice != 3);
}

//============ 统计租车次数 ============
void StatisticsRentalCnt()
{
    char n[20];
    int cnt=0;
    struct Rental *p = rentalHead;
    printf("请输入要查询的姓名:");
    scanf("%s",n);
    while(p != NULL){
        if(strcmp(p->name,n) == 0){
            cnt++;
        }
        p = p->next;
    }
    if(cnt == 0){
        printf("未查找到该用户的租车记录。\n");
    }else{
        printf("%s的租车次数:%d\n",n,cnt);
    }
}

//============ 统计违约次数 ============
void StatisticsViolationCnt()
{
    char n[20];
    int cnt=0;
    struct Rental *p = rentalHead;
    printf("请输入要查询的姓名:");
    scanf("%s",n);
    while(p != NULL){
        if(strcmp(p->name,n) == 0 &&  p->isViolated == 'Y'){
            cnt++;
        }
        p = p->next;
    }
    if(cnt == 0){
        printf("未查找到该用户的租车记录。\n");
    }else{
        printf("%s的违约次数:%d\n",n,cnt);
    }
}

//============ 确认11位电话号码 ============
int checkPhone(char p[])
{
    int i;
    if(strlen(p) != 11){
        return 0;
    }
    for(i = 0; i < 11; i++){
        if(p[i] < '0' || p[i] > '9'){
            return 0;
        }
    }
    return 1;
}

//============ 写文件 ============
void SaveData()
{
    FILE *fp = fopen("/Users/yida/Desktop/ARecord.txt", "wb");   //输出数据，打开一个二进制文件
    struct Renter  *rp;        //租车人信息
    struct Vehicle *vp;        //车辆信息
    struct Rental  *tp;        //租车信息
    if(fp == NULL){
        printf("\ncannot open file\n");
        return;
    }
    fwrite(&rentercnt,sizeof(int),1,fp);
    for(rp = renterHead;rp != NULL;rp = rp->next){
        fwrite(rp,sizeof(struct Renter),1,fp);
    }

    fwrite(&vehiclecnt,sizeof(int),1,fp);
    for(vp = vehicleHead;vp != NULL;vp = vp->next){
        fwrite(vp,sizeof(struct Vehicle),1,fp);
    }

    fwrite(&rentalcnt,sizeof(int),1,fp);
    for(tp = rentalHead;tp != NULL;tp = tp->next){
        fwrite(tp,sizeof(struct Rental),1,fp);
    }

    fclose(fp);
    printf("数据已保存。\n");
}

//============ 读文件 ============
void LoadData()
{
    FILE *fp = fopen("/Users/yida/Desktop/ARecord.txt", "rb");   //输入数据，打开一个二进制文件
    struct Renter  *rp, *rtail;
    struct Vehicle *vp, *vtail;
    struct Rental  *tp, *ttail;
    int i;
    if(fp == NULL){
        return;
    }
    fread(&rentercnt,sizeof(int),1,fp);
    rtail = NULL;
    for(i = 0;i < rentercnt;i++){
        rp = (struct Renter*)malloc(sizeof(struct Renter));
        fread(rp,sizeof(struct Renter),1,fp);
        rp->next = NULL;
        if(rtail == NULL){
            renterHead = rp;
        }else{
            rtail->next = rp;
        }
        rtail = rp;
    }

    fread(&vehiclecnt,sizeof(int),1,fp);
    vtail = NULL;
    for(i = 0;i < vehiclecnt;i++){
        vp = (struct Vehicle*)malloc(sizeof(struct Vehicle));
        fread(vp,sizeof(struct Vehicle),1,fp);
        vp->next = NULL;
        if(vtail == NULL){
            vehicleHead = vp;
        }else{
            vtail->next = vp;
        }
        vtail = vp;
    }

    fread(&rentalcnt,sizeof(int),1,fp);
    ttail = NULL;
    for(i = 0;i < rentalcnt;i++){
        tp = (struct Rental*)malloc(sizeof(struct Rental));
        fread(tp,sizeof(struct Rental),1,fp);
        tp->next = NULL;
        if(ttail == NULL){
            rentalHead = tp;
        }else{
            ttail->next = tp;
        }
        ttail = tp;
    }

    fclose(fp);
    printf("数据读取完成。\n");
}