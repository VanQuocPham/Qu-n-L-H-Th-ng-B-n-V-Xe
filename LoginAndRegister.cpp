#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Account   //Khai báo class tài khoản
{
    private:    //private kiểu khai báo các thuộc tính ở chế độ riêng tư chỉ có những hàm thuộc lớp mới có thể dùng được 
//các thuộc tính của lớp
    string username ;
    string password ;
    
    public: // các phương thức (method) của lớp   
        bool Login();
        void WriteInfor();
        void Input();
};
void Account::Input()
{
    cin.ignore();// dùng để xóa tất cả các bộ đệm trong C++ tương đương fflush(stdin)
    cout<<"Enter username of you: ";
    getline(cin,username);
    cout<<"\nEnter password of you: ";
    getline(cin,password);
}
bool Account::Login()
{   ifstream filein; //Khai báo biến dùng để đọc file
    string un,pw; //khai báo 2 biến tương đương với username and  password dùng để kiểm tra tài khoản
    Input();
    filein.open("Login.txt",ios_base::in );
    getline(filein,un);
    getline(filein,pw);
    if(un == username && pw == password)//kiểm tra điều kiện thỏa không
    {
        return true; // nếu đúng trả về true
    }
    else 
        return false;//sai trả về false
}
void Account::WriteInfor()
{
    Input();
    ofstream fileout;
    fileout.open("Login.txt",ios_base :: out);
    fileout<<username<<"\n"<<password;
    fileout.close();
}
int main ()
{
    Account Acc;
    ifstream filein;
    ofstream fileout;
    char choice ;
    // Acc.Input();
    while(true)
    {
        system("cls");
    cout<<"1: Registration\n2: Login\n3: Exit\n";
    cout<<"Please choice: ";
    cin>>choice;
    switch (choice)
    {
    case '1':
    {
        cout<<"Registration: \n";
        // Acc.Input();
        Acc.WriteInfor();
        break;
    }
    case '2':
    {   
        // Acc.Input();
        bool status = Acc.Login();
        if(status == true)
        {
            cout<<"\n Successfully Logined in !!!";
            return 0;
        }
        else 
            cout<<"\n Login Failed !!!";
            return 1;
        break;
    }
    case '3':
    {
        exit(1);
        break;
    }
    default : 
    {
        cout<<"Error....Please Enter again !!!";
    }
    }
    }
    return 0;
}