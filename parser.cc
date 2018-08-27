#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
#include<fstream>
typedef struct header{
  char packetLength[4];
  char noOfUpdates[2];
}header_t;

typedef struct quote{
  char length[4];
  char symbol[5];
  char type;
  char priceLevel[2];
  char priceLevelSize[4];
  char priceLevelPrice[8];
  char *dynamic;
}quote_t;
typedef struct trade{
  char length[4];
  char symbol[5];
  char type;
  char tradeSize[4];
  char tradePrice[8];
  char *dynamic;
}trade_t;
int main(){

  trade_t *trd;
  ifstream myFile("input001.txt");
  try{
    int tillNowLength=0;
    do {
  header_t *hdr = new header_t[6];
      myFile.seekg(tillNowLength,ios::beg); 
      memset(hdr->packetLength,'\0',4);
      myFile.read(hdr->packetLength,4);
      if (myFile.eof())
        return 0;
      
//    cout<<"hdr->packetLength = : <"<<hdr->packetLength<<">"<<endl;
//    cout<<"hdr->packetLength = : "<<stoi(hdr->packetLength,nullptr,10)<<endl;
      tillNowLength += stoi(hdr->packetLength,nullptr,10);
      memset(hdr->noOfUpdates,'\0',2);
      myFile.read(hdr->noOfUpdates,2);
      int trxs = stoi(hdr->noOfUpdates,nullptr,10);
//    cout<<"hdr->noOfUpdates = : "<<trxs<<endl;
      for ( int i = 0 ; i <trxs;i++){
        char dataLength[4]={'\0'};
        myFile.read(dataLength,4);
//      cout<<"dataLength = : "<<stoi(dataLength,nullptr,10)<<endl;
        trd = new trade_t[stoi(dataLength,nullptr,10)];
        memset(trd,0,stoi(dataLength,nullptr,10));
        char ch[1]={'\0'};
        myFile.seekg(5,ios::cur);
        myFile.read(ch,1);
//      cout<<"ch  = : "<<ch[0]<<endl;
        myFile.seekg(-10,ios::cur);
        if ( ch[0] == 'T' ){
//        cout<<"this is a trade"<<endl;
          myFile.seekg(4,ios::cur);
          memset(trd->symbol,'\0',5);
          myFile.read(trd->symbol,5);
//        cout<<"trd->symbol  = : "<<trd->symbol<<endl;
          myFile.seekg(1,ios::cur);
          memset(trd->tradeSize,'\0',4);
          myFile.read(trd->tradeSize,4);
//        cout<<"trd->tradeSize  = : "<<trd->tradeSize<<endl;
          int tSize = stoi(trd->tradeSize,nullptr,10);
          memset(trd->tradePrice,'\0',8);
          myFile.read(trd->tradePrice,8);
//        cout<<"trd->tradePrice  = : "<<trd->tradePrice<<endl;
          //cout<<tSize<<" "<<trd->symbol<<" @ "<<stof(trd->tradePrice)<<endl;  
          printf("%d %s @ %.2f\n",tSize,trd->symbol,stof(trd->tradePrice));
        }
        else {
//        cout<<"this is not a trade"<<endl;
          myFile.seekg(stoi(dataLength,nullptr,10),ios::cur); 
        }
        delete trd;
      }
    }while (!myFile.eof()); 
  }
  catch(exception &e){
    cout<<e.what()<<endl;
  }
  myFile.close();
}
