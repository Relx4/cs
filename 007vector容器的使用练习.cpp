#include<iostream>
#include<vector>
using namespace std;
void PrintVector(vector<int> vr, int num);
int main(int argc, char const *argv[]) {
    vector<int> vr;
    for(int i=0;i<10;i++){
        vr.push_back(i);
    }/*初始化一个数组*/
    PrintVector(vr, vr.size());/*打印这个数组*/
    vector<int> new_one={15,18,21};/*创建一个新的数组*/
    vr.insert(vr.begin()+1, new_one.begin(), new_one.end());/*将这个新数组插入到1号（第二个）元素之前*/
    PrintVector(vr, vr.size());/*打印插入后的效果*/
    vr.erase(vr.begin()+1, vr.begin()+4);/*将插入的新数组删除掉*/
    PrintVector(vr, vr.size());/*打印删除后的效果*/
    return 0;
}
void PrintVector(vector<int> vr, int num){
    cout<<"Print begin."<<endl;
    for(int i=0;i<num;i++){
        cout<<vr[i]<<endl;
    }
    cout<<"Print is over."<<endl;
}/*用于打印数组的函数*/
