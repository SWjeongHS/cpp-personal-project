#include <cstdlib>//������ ���
#include <ctime>
using namespace std;

int* distributeCard(int usercount, int cardNum[], int releasedCount){//die�� ���ϰ� ����ִ� �����, ���� ��е� ī�� ����, �󸶳� ����������� �Ѱܹް�, ��е� ī�尡 ������ �迭�� ������ �ȵǴϱ� ���������
    const int card[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};//1~10 ���� ī�� 2�徿 ���ʷ� 1-1,1-2,2-1,2-2...9-1,9-2,10-1,10-2�� �����ϴ� ��, �ٲ�� �ȵ�
    int checkDup[10]={0,};//�켱 5����� ī�� �й��ϴµ� �ߺ��˻� �� ����� �迭
    int cardCount = 0;
    int checkCount;
    int tmpnum;
    bool isDup=false;
    srand((unsigned int)time(NULL));

    for(int i=0; i<releasedCount; i++){//�̹� Ǯ���ִ� ������ �ٽ� ����, ��? �ߺ��� �а� ������ �ȵǴϱ�.
        checkDup[i]=cardNum[i];
        cardCount++;
    }
    
    for(int i=0; i<usercount; i++){//�Է� ���� ���� ����ŭ
        isDup = false;
        while(isDup==false){//���� �Ѹ��� ī�尡 ���� ī��� ��ġ����
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
            if(checkCount==cardCount){//������ ���Ҵµ� ��ġ�� ���� �������� ī�� �߰�
                checkDup[cardCount]=card[tmpnum];
                cardCount++;
                isDup = true;
            }
        }
    }
    return checkDup;
}
