#include <bits/stdc++.h>

using namespace std;

#define mod (long long)1000000007

#define ll long long 

#define ld long double
class player{
    int hp;
    int item1;//knife
    int item2;//magnifying glass
    int item3;//drink
    int item4;//hand cuff
    int item5;// cigar
    map<int,int>store;
    public :
    player(){
        hp=6;
        item1=0;
        item2=0;
        item3=0;
        item4=0;
        item5=0;
    }
    void display(){
        cout<<"Hp : "<<hp<<'\n';
        cout<<"Knife count : "<<store[1]<<'\n';
        cout<<"Magnifying glass count : "<<store[2]<<'\n';
        cout<<"Drink count : "<<store[3]<<'\n';
        cout<<"Hand cuff count : "<<store[4]<<'\n';
        cout<<"Cigar count : "<<store[5]<<'\n';
        // cout<<"Knife count : "<<item1<<'\n';
        // cout<<"Magnifying glass count : "<<item2<<'\n';
        // cout<<"Drink count : "<<item3<<'\n';
        // cout<<"Hand cuff count : "<<item4<<'\n';
        // cout<<"Cigar count : "<<item5<<'\n';
        
    }
    int currentHp(){
        return hp;
    }
    void add(int pos){
        store[pos]++;
        // if(pos==1)item1++;
    }
    bool checkval(int pos){
        if(store[pos]>0){store[pos]--;return true;}
        return false;
    }
    void incHp(int value){
        hp=hp+value;
    }

};

int main(){
    // start fun
    cout<<"start\n";
    cout<<"press any key\n";
    char anykey;
    cin>>anykey;
    while(1){
        player human , Bot;
        
        string name;
        cout<<"Enter your name\n";
        cin>>name;
        cout<<"In this game there will be a gun\n";
        cout<<"Let Gun carry n bullets\n";
        cout<<"So these bullet can be either real or fake\n";
        // cout<<"turn will be given to you and bot\n";
        cout<<"First turn will be yours\n";
        cout<<"Next turn will be of Bot\n";
        cout<<"Both of you have 6-6 life\n";
        cout<<"You can shoot either yourself or Bot\n";
        cout<<"If you shoot youself and the current bullet is fake ,So turn of other one will get skip so you get another turn again\n";
        cout<<"Or If you shoot yourself and current bullet is real one so you will lost 1 life\n";
        cout<<"But if you shoot other one then if it contain real bullet so other one will loose 1 life\n";
        cout<<"Both of you get 4 items also and each item is at max one time but both of you get these before reloading of gun\n";
        cout<<"Item 1 : Knife\n";
        cout<<"It increase damage of bullet 2X\n";
        cout<<"Item 2 : Magnifying glass\n";
        cout<<"You can see if current bullet is real of fake\n";
        cout<<"Item 3 : Drink\n";
        cout<<"This eject current bullet\n";
        cout<<"Item 4 : Handcuff\n";
        cout<<"This skip your opponent's turn so you get turn twice\n";
        cout<<"Item 5 : Cigar\n";
        cout<<"It increases you hp by 1\n";

        int bulletcount=0;
        int realBullet=0;
        int fakeBullet=0;
        int round=1;
        cout<<"\n\n\n";
        while(human.currentHp()>0&&Bot.currentHp()>0){

            if(bulletcount==0){
                cout<<"Round number : "<<round<<"\n";
                round++;
                srand(time(0)); 
                bulletcount=rand()%8;
                bulletcount++;
                realBullet=rand()%bulletcount;
                realBullet++;
                fakeBullet=bulletcount-realBullet;
                cout<<"Bullet count : "<<bulletcount<<"\n";
                cout<<"Real Bullet count : "<<realBullet<<"\n";
                cout<<"Fake bullet count : "<<fakeBullet<<"\n";
                int addtime=0;
                while(addtime<4){
                    int curritem=rand()%5;
                    curritem++;
                    human.add(curritem);
                    addtime++;
                }
                addtime=0;
                while(addtime<4){
                    int curritem=rand()%5;
                    curritem++;
                    Bot.add(curritem);
                    addtime++;
                }
            }
            cout<<"\n\n\n";
            queue<int>q;
            for(int p=0;p<bulletcount&&realBullet>0&&fakeBullet>0;p++){
                int currbullet=rand()%2;
                currbullet++;
                q.push(currbullet);
                if(currbullet==1)realBullet--;
                else fakeBullet--;
            }
            bulletcount=0;
            while(realBullet>0){
                q.push(1);
                realBullet--;
            }
            while(fakeBullet>0){
                q.push(0);
                fakeBullet--;
            }
            // cout<<1<<" "<<human.currentHp()<<Bot.currentHp()<<"\n";
            // human turn 
            while(human.currentHp()>0&&Bot.currentHp()>0&&q.size()>0){

            int turn=1;
            int damage=1;
            while(turn>0&&q.size()>0){
                cout<<"Your turn\n";
                cout<<"Your stats\n";
                human.display();
                cout<<"Bot stats\n";
                Bot.display();
                cout<<"Choose option\n";
                cout<<"1. to attack other one \n";
                cout<<"2. to attack yourself one \n";
                cout<<"3. to use knife \n";
                cout<<"4. to use magnifying glass \n";
                cout<<"5. to use Drink \n";
                cout<<"6. to use Hand cuff\n";
                cout<<"7. to use Cigar\n";
                int option;
                cin>>option;
                cout<<"Choosen option is : "<<option<<"\n";
                if(option==1||option==2){
                    turn--;
                    if(option==1){
                         cout<<"Current bullet is : ";
                        if(q.front()==1)cout<<"Real Bullet\n";
                        else cout<<"Fake Bullet\n";
                        if(q.front()==1){cout<<"Shoot\n";
                        Bot.incHp(-damage);
                        }
                        else{
                            cout<<"Missed\n";
                        }
                    }
                    else{
                         cout<<"Current bullet is : ";
                        if(q.front()==1)cout<<"Real Bullet\n";
                        else cout<<"Fake Bullet\n";
                        if(q.front()==1){cout<<"Ahh sh*t \n";
                            human.incHp(-damage);
                        }
                        else{
                            cout<<"ohh God!!\n";
                        }
                    }
                    q.pop();
                    damage=1;
                }
                else{
                    if(option==3&&human.checkval(option-2)){
                        cout<<"Now you can damage twice in one move\n";
                        damage=2;
                    }
                    if(option==4&&human.checkval(option-2)){
                        cout<<"Current bullet is : ";
                        if(q.front()==1)cout<<"Real Bullet\n";
                        else cout<<"Fake Bullet\n";
                    }
                    if(option==5&&human.checkval(option-2)){
                        cout<<"Current bullet which is ejected is : ";
                        if(q.front()==1)cout<<"Real Bullet\n";
                        else cout<<"Fake Bullet\n";
                        q.pop();

                    }
                    if(option==6&&human.checkval(option-2)){
                        turn++;
                        cout<<"Now you have two turn continuously\n";
                    }
                    if(option==7&&human.checkval(option-2)){
                        human.incHp(1);
                        cout<<"your hp increases by one\n";
                    }
                }
                cout<<"\n\n";

            }
            turn =1;
            damage=1;
            while(turn>0&&q.size()>0){
                cout<<"Bot turn\n";
                cout<<"Your stats\n";
                human.display();
                cout<<"Bot stats\n";
                Bot.display();
                cout<<"Choose option\n";
                cout<<"1. to attack other one \n";
                cout<<"2. to attack yourself one \n";
                cout<<"3. to use knife \n";
                cout<<"4. to use magnifying glass \n";
                cout<<"5. to use Drink \n";
                cout<<"6. to use Hand cuff\n";
                cout<<"7. to use Cigar\n";
                int option;
                option=rand()%7;
                option++;
                cout<<"Choosen option is : "<<option<<"\n";
                if(option==1||option==2){
                    turn--;
                    if(option==1){
                         cout<<"Current bullet is : ";
                        if(q.front()==1)cout<<"Real Bullet\n";
                        else cout<<"Fake Bullet\n";
                        if(q.front()==1){cout<<"Shoot\n";
                        human.incHp(-damage);
                        }
                        else{
                            cout<<"Missed\n";
                        }
                    }
                    else{
                         cout<<"Current bullet is : ";
                        if(q.front()==1)cout<<"Real Bullet\n";
                        else cout<<"Fake Bullet\n";
                        if(q.front()==1){cout<<"Ahh sh*t \n";
                            Bot.incHp(-damage);
                        }
                        else{
                            cout<<"Safe!!\n";
                        }
                    }
                    q.pop();
                    damage=1;
                }
                else{
                    if(option==3&&Bot.checkval(option-2)){
                        cout<<"Now you can damage twice in one move\n";
                        damage=2;
                    }
                    if(option==4&&Bot.checkval(option-2)){
                        cout<<"Current bullet is : ";
                        if(q.front()==1)cout<<"Real Bullet\n";
                        else cout<<"Fake Bullet\n";
                    }
                    if(option==5&&Bot.checkval(option-2)){
                        cout<<"Current bullet which is ejected is : ";
                        if(q.front()==1)cout<<"Real Bullet\n";
                        else cout<<"Fake Bullet\n";
                        q.pop();

                    }
                    if(option==6&&Bot.checkval(option-2)){
                        turn++;
                        cout<<"Now you have two turn continuously\n";
                    }
                    if(option==7&&Bot.checkval(option-2)){
                        Bot.incHp(1);
                        cout<<"your hp increases by one\n";
                    }
                }
                cout<<"\n\n";
            }

        }
        }
        cout<<"\n\n\n";
        cout<<"Winner is : ";
        if(human.currentHp()>0)cout<<name<<"\n";
        else cout<<"Bot\n";






        cout<<"want to retry\n";
        cout<<"click y\n";
        cout<<"click n\n";
        char retry;
        cin>>retry;
        if(retry=='n'){
            break;
        }
    }
    

return 0; 
}