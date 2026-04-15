#include<iostream>
using namespace std;
int main(){
    int count,test_cases;
    cin>>test_cases;;
    for(count=0; count<test_cases; count++){
        int width_of_car,length_of_car,amount_of_electricity,electricity_per_step;
        cin>>width_of_car;
        cin>>length_of_car;
        cin>>amount_of_electricity;
        cin>>electricity_per_step;
        int total_number_of_laps=(amount_of_electricity/(2*(width_of_car+length_of_car)*electricity_per_step));
        cout<<total_number_of_laps<<endl;
    }
}
