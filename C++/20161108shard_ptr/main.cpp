#include<iostream>
#include<boost/smart_ptr.hpp>
using namespace std;
using namespace boost;

#if 0
int main()
{
    int *p = new int(10);
    int *q = new int(200);
    shared_ptr<int> ps(p);
    cout<<*ps<<endl;
    cout<<"use_count_ = "<<ps.use_count()<<endl;
    cout<<ps.unique()<<endl;
    
    shared_ptr<int> ps1(ps);
    cout<<"use_count_ = "<<ps1.use_count()<<endl;
    cout<<ps1.unique()<<endl;

    return 0;
}
#endif

