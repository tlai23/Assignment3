#include "person.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

int readData(vector<Person> &employee);
void getCompanies(vector<Person> &employee, int n , vector <string> &companyNames);
void printHighestPaid(vector<Person> &employee, int n);
void separateAndSave(vector<Person> &employee, int n, vector<string> &companyNames);

int main()
{
  int N;
  vector<Person> employee;
  vector<string> companyNames;

  N = readData(employee);
  getCompanies(employee, N-1, companyNames);
  printHighestPaid(employee, N-1);
  separateAndSave(employee, N-1, companyNames);

}


  int readData(vector<Person> &employee)
  {
    Person p;
    string first, last, comp;
    int id;
    float hr, payR;
    int i=0;
    ifstream inData ("input.txt");
    if(inData.is_open())
    {
      while(inData)
      {
        inData>>first;
        inData>>last;
        inData>>id;
        inData>>comp;
        inData>>payR;
        inData>>hr;

        p.setFirstName(first);
        p.setLastName(last);
        p.setEmployeeId(id);
        p.setCompanyName(comp);
        p.setPayRate(payR);
        p.setHoursWorked(hr);
        employee.push_back(p);

        i++;
      }
      inData.close();
    }
    return i;
  }

  void getCompanies(vector<Person> &employee, int n, vector<string> &companyNames)
  {
    for(int i=0; i<n; i++)
    {
    string compN = employee.at(i).getCompanyName();
    companyNames.push_back(compN);
    }
  }

      void printHighestPaid(vector<Person> &employee, int n)
      {
        int a=0 ;
        float b=0;
        for(int i=0; i<n; i++)
        {
          float pay = employee.at(i).totalPay();
          if(pay>b)
          {
            b = pay;
            a = i;
          }
        }

        cout<< "Highest paid: "<<employee.at(a).getFirstName()<<" "<<employee.at(a).getLastName()<<endl;
        cout<<"Employee ID: "<<employee.at(a).getEmployeeId()<<endl;
        cout<<"Employer: "<<employee.at(a).getCompanyName()<<endl;
        cout<<"Total Pay: "<<setprecision(6)<<employee.at(a).totalPay()<<endl;
      }

      void separateAndSave(vector<Person> &employee, int n, vector<string> &companyNames)
      {
        for(int i=0; i<n;i++)
        {
        string a = companyNames.at(i);
        string b = a+".txt";
        ofstream outData (b , std::ios_base::app);
        outData<<setw(9)<<left<<employee.at(i).getFirstName()<<setw(9)<<left<<employee.at(i).getLastName()<<setw(7)<<left<<employee.at(i).getEmployeeId()<<setw(4)<<left<<employee.at(i).getCompanyName()<<"  "<<"$"<<employee.at(i).totalPay()<<endl;
        outData.close();
        }
      }
