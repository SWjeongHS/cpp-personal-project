#include <cstdlib>//랜덤용 헤더
#include <ctime>
using namespace std;

int* distributeCard(int usercount, int cardNum[], int releasedCount){//die를 안하고 살아있는 사람수, 현재 배분된 카드 정보, 얼마나 나눠줬는지를 넘겨받고, 배분된 카드가 없으면 배열값 이전이 안되니까 상관없을듯
    const int card[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};//1~10 월별 카드 2장씩 차례로 1-1,1-2,2-1,2-2...9-1,9-2,10-1,10-2에 대응하는 값, 바뀌면 안됨
    int checkDup[10]={0,};//우선 5명까지 카드 분배하는데 중복검사 및 저장용 배열
    int cardCount = 0;
    int checkCount;
    int tmpnum;
    bool isDup=false;
    srand((unsigned int)time(NULL));

    for(int i=0; i<releasedCount; i++){//이미 풀려있는 값들을 다시 저장, 왜? 중복된 패가 나가면 안되니까.
        checkDup[i]=cardNum[i];
        cardCount++;
    }
    
    for(int i=0; i<usercount; i++){//입력 받은 유저 수만큼
        isDup = false;
        while(isDup==false){//새로 뿌리는 카드가 기존 카드와 겹치는지
            checkCount = 0;
            tmpnum = rand()%20;
            for(int j=0; j<cardCount; j++){
                if(checkDup[j]==card[tmpnum]){
                    break;
                }
                else{
                    checkCount++;
                }
            }
            if(checkCount==cardCount){//끝까지 돌았는데 겹치는 값이 없었으면 카드 추가
                checkDup[cardCount]=card[tmpnum];
                cardCount++;
                isDup = true;
            }
        }
    }
    return checkDup;
}
