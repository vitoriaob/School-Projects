#include <iostream>
using namespace std;

struct Person{
    string name;
    int age;
};

int main(){
    int N;
    cin >> N;
    
    struct Person* people = new struct Person[N];
    
    for (int i=0; i<N; i++)
        cin >> people[i].name >> people[i].age;
    
    for(int i=0; i<N; i++)
        cout << "Name: " << people[i].name << ", Age:" << people[i].age << endl;
    
    delete[] people;
    
    return 0;
}
