#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode
{

    char d;
    unsigned freq;
    MinHeapNode *lChild, *rChild;

    MinHeapNode(char d, unsigned freq)
    {
        lChild = rChild = NULL;
        this->d=d;
        this->freq=freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
         return (l->freq > r->freq);
    }
};

void printCode(struct MinHeapNode *root, string str)
{
    if (!root)
        return;
    if (root->d !='$')
        cout<<root->d<<": "<<str<<"\n";

    printCode(root->lChild, str+"0");
    printCode(root->rChild, str+"1");

}

void HuffmanCode(char d[],int freq[],int size)
{
    struct MinHeapNode *lChild, *rChild, *top;

    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
    for(int i=0; i<size; i++)
        minHeap.push(new MinHeapNode(d[i],freq[i]));

    while(minHeap.size() !=1)
    {
       lChild = minHeap.top();
        minHeap.pop();


        rChild=minHeap.top();
        minHeap.pop();

        top= new MinHeapNode('$', lChild->freq + rChild->freq);
        top->lChild=lChild;
        top->rChild=rChild;

        minHeap.push(top);

    }
    printCode(minHeap.top()," ");
}

int main()
{
    char arr[] = {'a', 'b','c','d','e','f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCode(arr,freq,size);
    return 0;
}
