 #include<iostream>
 #include<string.h>
 using namespace::std;
 template <typename t>
  class planet{
        t sector;
        char name[20];
        int population;
        int awardswin;
    public:
        planet()
        {

        }
        planet(t sec,char n[],int p,int a)
        {
            strcpy(name,n);
            population=p;
            awardswin=a;
            sector=sec;
        }
        void getname()
        {
            cout<<name;
        }
        void infoplanet()
        {
            cout<<name<<"  "<<population<<"  "<<awardswin<<"  "<<sector;

        }
      void operator =(planet &p2)
       {
         strcpy(name,p2.name);
         population=p2.population;
         awardswin=p2.awardswin;
         sector=p2.sector;
       }

        friend void searchplanet(char *a,planet<int> *p[],int indpl);
        friend void searchplanet(int sect,planet<int> *p[],int indpl);
 };
 void searchplanet(char *a,planet<int> *p[],int indpl)
 {
    int f=0;
    for(int i=0;i<indpl;i++)
    {
        if(strcmp((p[i]->name),a)==0)
        {
            p[i]->infoplanet();
            f=1;
        }
    }
try
{
    if(f==0)
        throw(0);
}
        catch(int s)
        {
            cout<<"\n sorry planet not found\n";
        }
 }
  void searchplanet(int a,planet<int> *p[],int indpl)
 {
    int f=0;
    for(int i=0;i<indpl;i++)
    {
        if((p[i]->sector)==a)
        {
            p[i]->infoplanet();
            f=1;
        }
    }
try
{
    if(f==0)
        throw(0);
}
        catch(int s)
        {
            cout<<"\n sorry planet not found\n";
        }

 }

 class member{
    protected:

      char name[20];
      planet<int>* add;
      int salary;
      int id;
        public:
        member()
        {
            strcpy(name,"g");
            salary=0;
        }
     member(int i,char na[],int s,planet<int>* p)
     {
         strcpy(name,na);
         salary=s;
         add=p;
         id=i;
     }
    void getsalary()
    {
        cout<<salary;
    }
    void setsalary(int a)
    {
        salary=a;
    }
    void getname()
    {
        cout<<name;
    }
    void setname(char n[])
    {
        strcpy(n,name);
    }
   /*void operator =(planet p2)
    {
        add.name=p2.name;
     add.population=p2.population;
    add.awardswin=p2.awardswin;

    }*/
    virtual int disp(int mid)=0;
 };

 class  president: public member
 {
     /*mibo agent;*/
     int noofyears;
 public:
     president()
     {

     }
    president(int i,int no,char na[],int s,planet<int>* p):member(i,na,s,p)
    {
    noofyears=no;
    add=p;
    }

    void setnoofyears(int n)
    {
        noofyears=n;
    }
    int getnoofyears()
    {
        return noofyears;

    }
    void getname()
    {
        cout<<name;
    }
    void infopresident()
    {
        cout<<name;
        cout<<"   ";
        add->infoplanet();
        cout<<"   ";
        cout<<salary<<"   ";
        cout<<noofyears<<"   ";

    }
    void operator =(president &p1)
    {
        strcpy(name,p1.name);
        add=p1.add;
        salary=p1.salary;
        noofyears=p1.noofyears;
        id=p1.id;
    }
    int disp(int mid)
    {
        try{
        if(id==mid)
        {

            cout<<"yes this is president ";


        }
        else
            throw 'd';
        }
    catch(...)
      {
          return 0;
          cout<<"not a president ";
      }
      return 1;
    }
 };
 class headofplanet:public member
 {
     planet<int>* pla;
     int noofyears;
 public:
     headofplanet()
     {

     }
    headofplanet(int i,int no,planet<int>* p,char *na,planet<int>* pn,int s):member(i,na,s,pn),noofyears(no)
    {
        pla=p;
    }
    void setnoofyears(int n)
    {
        noofyears=n;
    }
    int getnoofyears()
    {
        return noofyears;

    }
    void operator =(headofplanet &p1)
    {
        strcpy(name,p1.name);
        add=p1.add;
        pla=p1.pla;
        salary=p1.salary;
        noofyears=p1.noofyears;
        id=p1.id;
    }
     void infohead()
    {
        cout<<name;
        cout<<"   ";
        add->infoplanet();
        cout<<"   ";
        pla->infoplanet();
        cout<<"   ";
        cout<<salary<<"   ";
        cout<<noofyears<<"   ";

    }
    friend void underwhom(char nam[20]);
    int disp(int mid)
    {
        try{
        if(id==mid)
        {
            cout<<"this is head of ";
            pla->getname();
        }
        else
            throw 'd';
        }
    catch(...)
      {
          return 0;
          cout<<"not a head of planet";
      }
      return 1;
    }
 };
 class representatives:public member
 {
     planet<int>* pla;

 public:
     representatives()
     {

     }
    representatives(int i,planet<int>* p,char *na,planet<int>* pn,int s):member(i,na,s,pn)
    {
        pla=p;
    }
    void operator =(representatives &p1)
    {
        strcpy(name,p1.name);
        add=p1.add;
        pla=p1.pla;
        salary=p1.salary;
        id=p1.id;
    }
     void inforep()
    {
        cout<<name;
        cout<<" lives at  ";
        add->infoplanet();
        cout<<" rep of  ";
        pla->infoplanet();
        cout<<"   ";
        cout<<salary<<"   ";


    }
    int disp(int mid)
    {
      try
      {
          if(id==mid)
           {
            cout<<"this is representative of ";
            pla->getname();

           }
        else
            throw 'd';
      }
      catch(...)
      {
          return 0;
          cout<<"not a representative";
      }
        return 1;
    }
    friend void underwhom(char nam[20]);
 };

 class membersofgn{
 headofplanet *head;
 representatives *rep;
 planet<int> *pla;
 public:
     membersofgn()
     {

     }
     membersofgn(headofplanet *h,representatives *r,planet<int>* p)
     {
        head=h;
        rep=r;
        pla=p;
     }
     void operator =(membersofgn &p1)
     {
         head=p1.head;
         rep=p1.rep;
         pla=p1.pla;
     }
     void infomem()
     {
         cout<<" info of head";
         head->infohead();
         cout<<"    info of rep";
         rep->inforep();
         cout<<"    info of planet";
         pla->infoplanet();
     }
        friend void underwhom(char nam[20]);
  };

 class gnassembly{
    president *pre;
    planet<int> *headqua;
    membersofgn *mem[2];
public:
    gnassembly()
    {

    }
    gnassembly(president *p,planet<int>* pla,membersofgn *me[2])
    {
        pre=p;
        headqua=pla;
        mem[0]=me[0];
        mem[1]=me[1];
    }
    void getinfogn()
    {   cout<<"info of president";
        pre->infopresident();
        cout<<"     info of headquaters";
        headqua->infoplanet();
        cout<<"     info of memnbers";
        mem[0]->infomem();
        cout<<"   ";
        mem[1]->infomem();
    }
     void operator =(gnassembly &p1)
    {
        pre=p1.pre;
        headqua=p1.headqua;
        mem[0]=p1.mem[0];
        mem[1]=p1.mem[1];
    }

 };

 class mibo
 {
     president *pre;
     planet<int> *pla;
     gnassembly *gn;
 public:
     mibo()
     {

     }
    mibo(president *p,planet<int> *pl,gnassembly *g)
    {
        pre=p;
        pla=pl;
        gn=g;
    }
     president* getpresident()
     {
         return pre;
     }
     void setpresident(president *p)
     {
        pre=p;

     }
     void getmibo()
     {
        cout<<" president of mibo     ";
        pre->infopresident();
        cout<<"    headqaters of mibo     ";
        pla->infoplanet();
        cout<<"     info of gnassembly    ";
        gn->getinfogn();
     }
     ~mibo()
     {
         delete gn;
     }

 };
void check(int a,president *pr[],headofplanet *he[],representatives *rep[],int indpr,int indhe,int indrep)
{
    int d=0,flag=0,i;
     member *m;

    for(i=0;i<indpr;i++)
    {
        m=pr[i];
        d=m->disp(a);
        if(d==1)
        {
            flag=1;
        }
    }
    if(flag==0)
    {
        for(i=0;i<indhe;i++)
        {
            m=he[i];
            d=m->disp(a);
            if(d==1)
            {
                flag=1;
            }
        }
    }
    if(flag==0)
    {
        for(i=0;i<indrep;i++)
        {
            m=rep[i];
            d=m->disp(a);
            if(d==1)
            {
                flag=1;
            }
        }
    }
    if(flag==0)
    {
        cout<<"id not found";
    }
}

  int main()
  {

      planet<int> *pl[10];
      pl[0]=new planet<int>(123,"xander",1203,12);
      pl[1]=new planet<int>(19,"nova",14034,34);
      pl[2]=new planet<int>(190,"elipta",23506,16);
      pl[3]=new planet<int>(140,"mandisa",8096,9);
      pl[4]=new planet<int>(150,"zoltar",3460,45);
        int indpl=5;

        //searchplanet("nov",pl);
        //searchplanet(19,pl);


       president *pr[5];
       pr[0]=new president(1,5,"gaurav",1200,pl[0]);
       pr[1]=new president(2,4,"naman",1100,pl[1]);
       int indpr=2;
       headofplanet *he[5];
       he[0]=new headofplanet(3,6,pl[3],"prateek",pl[2],1000);
       he[1]=new headofplanet(4,6,pl[4],"anand",pl[2],1000);
       int indhe=2;
       representatives *rep[5];
       rep[0]=new representatives(5,pl[3],"vivek",pl[4],900);
       rep[1]=new representatives(6,pl[4],"sanket",pl[4],900);
       int indrep=2;


       //check(10,pr,he,rep);


      membersofgn *mem[2];
      mem[0]=new membersofgn(he[0],rep[0],pl[3]);
      mem[1]=new membersofgn(he[1],rep[1],pl[3]);


      gnassembly *g=new gnassembly(pr[1],pl[1],mem);
    //  g.getinfogn();
    mibo m(pr[0],pl[0],g);

       char h='y';
       do{
            cout<<"welcome to mibo"<<endl<<"enter 1 to search a planet"<<endl<<"enter 2 to check a id"<<endl<<"enter 3 to add a planet";
       cout<<endl<<"enter 4 to add a president"<<endl<<"enter 5 to add a head of the planet"<<endl<<"enter 6 to add a representative";
        int a;
       cin>>a;
       if(a==1)
       {
           int b;
           l1:
           cout<<"press 1 to search by name and 2 to search by sector no.";
           cin>>b;
       try{
           if(b==1)
           {
               char n[20];
               cin>>n;
               searchplanet(n,pl,indpl);
           }
           else if(b==2)
           {
               cin>>b;
               searchplanet(b,pl,indpl);
           }
           else
            throw 'g';
       }
       catch(...)
       {
           cout<<"enter 1 or 2";
           goto l1;
       }
       }
       if(a==2)
       {
           int c;
           cout<<"enter the id";
           cin>>c;
           check(c,pr,he,rep,indpr,indhe,indrep);
       }
       if(a==3)
       {
           char na[20];
           int p,n,d;
           cout<<"enter sector no. of planet";
           cin>>d;
           cout<<"enter the name of the planet";
           cin>>na;
           cout<<"enter the population";
           cin>>p;
           cout<<"enter no  of awards win";
           cin>>n;
           pl[indpl]=new planet<int>(d,na,p,n);
           pl[indpl]->infoplanet();
           indpl++;

       }
       if(a==5)
       {
           char na[20];
           int p,n,ten,t,e;
           cout<<"enter the id of member";
           cin>>e;
           cout<<"enter the tenure";
           cin>>ten;
           cout<<"enter th index of the planet of which he is head";
           cin>>t;
           cout<<"enter the name";
           cin>>na;
           cout<<"enter salary in drcamas";
           cin>>n;
           cout<<"enter index of planet from 0 to "<<indpl;
           cin>>p;
           he[indhe]=new headofplanet(e,ten,pl[t],na,pl[p],n);
           //pl[indpl]=new planet<int>(a,na,p,n);
           //pl[indpl]->infoplanet();
           he[indhe]->infohead();
           indhe++;

       }
       if(a==4)
       {
           char na[20];
           int p,n,ten,f;
           cout<<"enter the id of member";
           cin>>f;
           cout<<"enter the tenure";
           cin>>ten;
           cout<<"enter the name";
           cin>>na;
           cout<<"enter salary in drcamas";
           cin>>n;
           cout<<"enter index of planet from 0 to "<<indpl;
           cin>>p;
           pr[indpr]=new president(f,ten,na,n,pl[p]);
           //pl[indpl]=new planet<int>(a,na,p,n);
           //pl[indpl]->infoplanet();
           pr[indpr]->infopresident();
           indpr++;

       }
        if(a==6)
       {
           char na[20];
           int p,n,ten,t,g;
           cout<<"enter the id of member";
           cin>>g;
           cout<<"enter th index of the planet of which he is representative";
           cin>>t;
           cout<<"enter the name";
           cin>>na;
           cout<<"enter salary in drcamas";
           cin>>n;
           cout<<"enter index of planet from 0 to "<<indpl;
           cin>>p;
           rep[indrep]=new representatives(g,pl[t],na,pl[p],n);
           //pl[indpl]=new planet<int>(a,na,p,n);
           //pl[indpl]->infoplanet();
           rep[indrep]->inforep();
           indrep++;

       }

       cout<<"enter y to continue and n to exit";
       cin>>h;
       }
       while(h=='y');

      return 0;

  }
