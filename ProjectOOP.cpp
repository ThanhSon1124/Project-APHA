#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
#define endl "\n"
#define ll long long
#define maxn 10005
class labor{
    private:
        string manv,hoten,ns,hopdong;
    public:
        labor(){
        }
        labor(string manv,string hoten,string ns,string hopdong){
            this->manv = manv;
            this->hoten = hoten;
            this->ns = ns;
            this->hopdong = hopdong;
        }
        void Intput(){
            cout << "Nhap manv :";getline(cin,manv);
            cout << "Nhap hoten :";getline(cin,hoten);
            cout << "Nhap nam sinh :";getline(cin,ns);
            cout << "Nhap loai hop dong :";getline(cin,hopdong);
        }
        void OutPut(){
            cout << "Ma nv :" << manv << endl;
            cout << "Ho ten :" << hoten << endl;
            cout << "Nam sinh :" << ns << endl;
            cout << "Loai hop dong :" << hopdong << endl;
        }
};
class seasonal_labor : public labor{
    private:
        int workday,daily_salary,reward;
    public:
        void Intput(){
            labor::Intput();
            cout << "Nhap so ngay cong :";cin >> workday;
            cout << "Nhap tien luong ngay cong :";cin >> daily_salary;
        }
        int allowance1(){
            if(workday >= 25){
                return this->workday * this->daily_salary + 1000000;
            }
            else return this->workday * this->daily_salary;
        }
        void OutPut(){
            labor::OutPut();
            cout << "So ngay cong :" << workday << endl;
            cout << "Tien luong ngay cong :" << daily_salary << endl;
            cout << "Tien thuong :" << allowance1() << endl;
        }
};

class official_staff : public labor{
    private:
        string chucvu;
        int coefficients_Salary,basic_Salary;
    public:
        void Intput(){
            labor::Intput();
            cout << "Nhap chuc vu :";getline(cin,chucvu);
            cout << "Nhap he so luong :";cin >> coefficients_Salary;
            cout << "Nhap luong co ban :";cin >> basic_Salary;
        }
        int allowance2(){
            if(chucvu=="Nhan vien"){
                return this->coefficients_Salary * this->basic_Salary + 500000;
            }
            else if(chucvu=="Pho phong"){
                return this->coefficients_Salary * this->basic_Salary + 700000;
            }
            else if(chucvu=="Truong phongf"){
                return this->coefficients_Salary * this->basic_Salary + 1000000;
            }
        }
        void OutPut(){
            labor::OutPut();
            cout << "Chuc vu :" << chucvu << endl;
            cout << "He so luong :" << coefficients_Salary << endl;
            cout << "Luong co ban :" << basic_Salary << endl;
            cout << "Tien thuong :" << allowance2() << endl;
        }
};
int main(){
    seasonal_labor sea[1005];
    int Sea = 0;
    official_staff off[1005];
    int Off = 0;
    int choose;
    while(1){
        cout << "\n---------------------MENU-------------------------\n";
        cout << "1.Nhap lao dong thoi vu" << endl;
        cout << "2.Nhap lao dong chinh thuc" << endl;
        cout << "3.Xuat Info" << endl;
        cout << "4.Thong ke cac lao dong theo tung hop dong" << endl;
        cout << "5.Exit" << endl;
        cout << "-----------------------------------------------------\n";
        cin >> choose;
        cin.ignore();
        switch(choose){
            case 1:
                Sea++;
                sea[Sea].Intput();
                break;
            case 2:
                Off++;
                off[Off].Intput();
                break;
            case 3:
                for(int i=1;i<=Sea;i++){
                    cout << "Lao dong thu " << i << endl; 
                    sea[i].OutPut();
                    cout << "---------------------" << endl;
                }
                for(int i=1;i<=Off;i++){
                    cout << "Nhan vien thu " << i << endl;
                    off[i].OutPut();
                    cout << "---------------------" << endl;
                }
                break;
            case 4:
                cout << "So luong hop dong lao dong thoi vu la :" << Sea << endl;
                cout << "So luong hop dong lao dong nhan vien chinh thuc :" << Off << endl;
                break;
            default:
                cout << "Exit!" << endl;
                break;
        }
    }
    return 0;
}