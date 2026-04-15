#include<iostream>
using namespace std;
int main(){
    int count,test_cases;
    cout<<"Enter the number of test cases:"<<endl;
    cin>>test_cases;;
    for(count=0; count<test_cases; count++){
        int width_of_car,length_of_car,amount_of_electricity,electricity_per_step;
        cout<<"Enter the input value for width of car:"<<endl;
        cin>>width_of_car;
        cout<<"Enter the input value for the length of car:"<<endl;
        cin>>length_of_car;
        cout<<"Enter the amount of electricity required:"<<endl;
        cin>>amount_of_electricity;
        cout<<"Enter the electricity per step:"<<endl;
        cin>>electricity_per_step;
        int total_number_of_laps=(amount_of_electricity/(2*(width_of_car+length_of_car)*electricity_per_step));
        cout<<"The total number of laps will be :"<<total_number_of_laps<<endl;
    }
}
