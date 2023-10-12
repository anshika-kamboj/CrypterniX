#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <forward_list>
using namespace std;
unordered_map<string,forward_list<string>> m;
unordered_map<string,int> extras;
 int flag;
void mydictionary()
{
    m["oil"]={"lubrication","petroleum","crude oil","liquid","carbon","vehicle"};
    m["old"] ={"antique","past","elderly","ancient","age","experience"};
    m["organic"] ={"chemistry","polymer","edible","fertilizer","structured","manured"};
    m["orchestra"]={"symphony","cello","concertmaster","piano","opera","concerto"};
    m["party"] = {"fete","social","dance","celebrate","political party","bash"} ;
    m["photography"]={"camera","solarize","science","art","lens","image"};
    m["power"] ={"strength","influence","ability","capacity","dominate","skill"};
    m["plant"]={"root","chlorophyll","water","botany","leaf","moss"} ;
    m["painting"]={"pigment","canvas","art","brush","latex","surface"};
    m["physics"]={"medicine","aloes","vehicle","heat","motion","reversibility"};
    m["pirate"]={"crime","ship","boat","hijack","movie","sea"};
    m["pirates"]={"crime","ship","boat","hijack","movie","sea"};
    m["poverty"]={"world bank","malnutrition","illiteracy","unemployment","corruption","life expectancy"};
    m["quality"]={"cloth","accuracy","caliber","excellence","prize","sufficiency"};
    m["quantum"] ={"physics","quantity","amount","particle","photon","measurement"};
    m["queen"]={"king","monarch","royalty","chess","england","monarch"};
    m["quiet"] ={"still","calm","hush","silence","silent","gentle"};
    m["quick"] = {"fast","speedy","nimble","ready","quickly","swift"};
    m["questions"] ={"answer","wonder","inquire","doubt","student","teacher"};
    m["question"]={"answer","wonder","inquire","doubt","student","examine"};
    m["quest"]={"invite","pursuit","beg","search","hunt","ask"};
    m["quilting"]={"patchwork","comforter","sew","rug","origami","sewing"};
    m["queer"]={"odd","funny","strange","fairy","singular","peculiar"};
    m["recycling"]={"reuse","waste","composting","energy","garbage","landfill"};
    m["rainfall"] ={"water","precipitation","monsoon","hail","climate","moisture"} ;
    m["religion"] ={"faith","belief","orthodox","ritual","theology","meditation"};
    m["reading"]={"interpret","see","understand","visualize","translate","writer"};
    m["royalty"]={"queen","king","monarch","highness","imperial","crown"};
    m["racism"]={"apartheid","Nazism","slavery","discrimination","prejudice","xenophobia"};
    m["rain-forest"]={"species","oxygen","jungle","tree","birds","wild"};
    m["research"] ={"experiment","science","investigate","inquiry","explore","knowledge"};
    m["resilience"]={"strength","confidence","elasticity","vibrancy","recoil","persistence"};
    m["relationship"]={"friend","kinship","association","state","partnership","family"};
    m["relationships"]={"friend","kinship","association","state","partnership","family"};
    m["safari"]={"jungle","browser","Africa","trekking","jungle","expedition"};
    m["science"]={"astronomy","research","observation","technology","knowledge","subjects"};
    m["shopping"] ={"browse","mall","store","payment","billing","market"};
    m["sustainability"]  ={"ecology","climate change", "energy","society","lifestyle","environment"};
    m["sound"]={"noise","voice","physics","concert","loud","ear"};
    m["summer"] ={"climate","season","hot","sun","bright","temperature"};
    m["snow"] ={"climate","rain","winter","season","ice","melting"};
    m["school"]={"student","teacher","questions","exam","rules","education"};
    m["table"]={"wood","chair","timber","furniture","row","chemistry"};
    m["travel"]= {"move","journey","free","trip","tourism","vehicle"};
    m["technology"]={"science","computer","Internet","innovation","equipment","industry"};
    m["trees"] ={"oxygen","wood","science","rain","water","climate"};
    m["textiles"] ={"clothes","business","government","silkworm","threads","clothes"};
}



 //to extract all words from string and insert those words into vector
vector <string> extract(string s)
{
    vector <string> w;
    string word=" ";
    int i;
    for(i=0;i<sizeof(s);i++)
    {
      if(s[i]==' ')
       {
        w.push_back(word.substr(1,(sizeof(word)-1)));
        word=' ';
       }
      else
       {
        word += s[i];
       }
    }
   // cout<<"\n in extract function \n";
   return w;
}


//this function returns the related words of the passed string as list
forward_list<string> embed(string key)
{
  unordered_map<string,forward_list<string>>::iterator it;
  it= m.find(key);
  //cout<<"\n in embed function \n";
  if(it==m.end())
   {
    cout<<endl<<key <<" is not in our domain please enter another statement \n";
    cout<<"****************************************************************************************************************************\n\n\n\n";
   }
   
   {
    (it->second).push_front(it->first);
   }
    return it->second;
}

void checkextra()
{
   extras["is"]=1;
   extras["and"]=2;
   extras["this"]=3;
   extras["or"]=4;
   extras["for"]=5;
   extras["in"]=6;
   extras["on"]=7;
   extras["that"]=8;
   extras["those"]=9;
   extras["their"]=10;
   extras["there"]=11;
   extras["for"]=12;
   extras["nor"]=13;
   extras["but"]=14;
   extras["yet"]=15;
   extras["so"]=16;
   extras["after"]=17;
   extras["although"]=18;
   extras["as"]=19;
   extras["much"]=20;
   extras["many"]=21;
   extras["because"]=22;
   extras["before"]=23;
   extras["even"]=24;
   extras["then"]=25;
   extras["if"]=26;
   extras["just"]=27;
   extras["now"]=28;
   extras["once"]=29;
   extras["than"]=30;
   extras["where"]=31;
   extras["which"]=32;
   extras["while"]=33;
   extras["more"]=34;
   extras["hence"]=35;
   extras["the"]=36;
}


unordered_map<string,int> relatedwords(vector<string> s)
{
   vector<string>::iterator t=s.begin();
   forward_list<string>::iterator it;
     while(extras.find(*t)!=extras.end())t++;
   forward_list<string> l = embed(*t);

   for(++t;t!=s.end();t++)
    {
          while(extras.find(*t)!=extras.end())t++;
       l.merge(embed(*t));
    }
   it=l.begin();
   unordered_map<string,int> words_with_frequency;
   unordered_map<string,int>::iterator i;//points to the word that already exist in map to increase its frequency
   words_with_frequency[*it]=1;
   for(++it;it!=l.end();it++)
   {
     i=words_with_frequency.find(*it);
      if(i!= words_with_frequency.end())
       {
        (words_with_frequency[*it])++;
       }
      else
       {
        words_with_frequency[*it]=1;
       }
   }
  // cout<<"\n at the end of relatedwords function \n";
  return  words_with_frequency;
}


void display(unordered_map<string,int> v)
{
    cout<<"\n\n\n    CLUES IN DECREASING STRENGTH ARE :";
    cout<<endl<<"\n    NOTE: the clue at the top has maximum probability to be true and \n    this probability decreases as we go down \n\n\n";
    unordered_map<string,int>:: iterator it;
    for(it=v.begin();it!=v.end();it++)
     {
        if(it->second>=3) cout<<"    ....."<<it->first<<".....     \n"<<endl;
     }
    for(it=v.begin();it!=v.end();it++)
     {
        if(it->second==2) cout<<"    ....."<<it->first<<".....     \n"<<endl;
     }
    for(it=v.begin();it!=v.end();it++)
     {
        if(it->second==1) cout<<"    ....."<<it->first<<".....     \n"<<endl;
     }
}

int main()
{
    cout<< endl<<endl<<endl;
    cout<<"     <>            <>   <><><><><>  <>           <><>        <><>      <><>      <><>   <><><><><>   \n";
    cout<<"     <>            <>   <>          <>         <>    <>    <>    <>    <> <>    <> <>   <>           \n";
    cout<<"     <>     <>     <>   <>          <>        <>          <>      <>   <>  <>  <>  <>   <>           \n";
    cout<<"     <>    <><>    <>   <><><>      <>        <>          <>      <>   <>   <><>   <>   <><><>       \n";
    cout<<"     <>   <>  <>   <>   <>          <>        <>          <>      <>   <>    <>    <>   <>           \n";
    cout<<"      <> <>    <> <>    <>          <>         <>    <>    <>    <>    <>          <>   <>           \n";
    cout<<"       <>       <>      <><><><><>  <><><><><>   <><>        <><>      <>          <>   <><><><><>   \n";
    cout<<"   __________________________________________________________________________________________________ \n";
    cout<<"   __________________________________________________________________________________________________  \n\n";
    mydictionary();

    cout<<"   -> 1 : SOLVE THE CRYPTIC CLUE \n ";
    cout<<"   -> 2 : RETURN TO HOMESCREEN  \n";
    cout<<"\n   ENTER YOUR CHOICE : ";
    cin>>flag;
    checkextra();
    getchar();
   while(flag==1)
   {
    string s,cop; //cop stores copy of s
    cout<<"\n\n ENTER THE STATEMENT :";
    getline(cin,s,'.'); //REMEMBER TO ADD A fullstop AT THE END AS HERE DELLIMETER IS '.' IT TAKES IN STRING TILL fullstop
    cop=s; //copy of entered string
    vector <string> words =extract(cop); //each word of string is input into words vector
    unordered_map<string,int> clues =relatedwords(words);
    display(clues);
     cout<<endl<<endl<<endl<<endl;
    cout<<"   -> 1 : SOLVE THE CRYPTIC CLUE \n ";
    cout<<"  -> 2 : RETURN TO HOMESCREEN  \n";
    cout<<"\n   ENTER YOUR CHOICE : ";
    cin>>flag;
    getchar();
   }
    if(flag==2)
    {
        cout<<"****************** THANKYOU FOR USING CRYPTIC CLUE SOLVER ******************\n";
      return 0;
    }
}
