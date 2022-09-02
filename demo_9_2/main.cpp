#include <iostream>

using namespace std;

//������
class TV
{
friend class Remote;
private :
    int mState; // ״̬
    int mVolume; //����
    int mChannel; //Ƶ��
    enum { On,Off}; //״̬ö��
    enum{ minVol, maxVol=100}; //����ö��
    enum{ minChannel = 1, maxChannel = 255}; //Ƶ��ö��
public :
    TV()
    {
        this->mState = Off;
        this->mVolume = minVol;
        this->mChannel = minChannel;
    }

    //���ص���
    void onOrOff(void)
    {
        this->mState = (this->mState == On ? Off:On);
    }

    //�Ӵ�����
    void volumeUp(void)
    {
        if(this->mVolume >= maxVol)
            return;
        this->mVolume++;
    }
    //��С����
    void volumeDown(void)
    {
        if(this->mVolume <= minVol)
            return;
        this->mVolume--;
    }

    //����Ƶ��
    void channelUp(void)
    {
        if(this->mChannel >= maxChannel)
            return;
        this->mChannel++;
    }
    //����Ƶ��
    void channelDown(void)
    {
        if(this->mChannel <= minChannel)
            return;
        this->mChannel--;
    }

    //��ʾ���ӻ���״̬
    void showTVState(void)
    {
        cout << "���ӻ�״̬Ϊ : " << (this->mState == On ? "����" : "�ػ�") << endl;
        cout << "���ӻ�������Ϊ : " << this->mVolume << endl;
        cout << "���ӻ���Ƶ�� : " << this->mChannel << endl;
    }

};

void test01()
{
    TV tv;
    tv.onOrOff();
    tv.volumeUp();
    tv.volumeUp();
    tv.volumeUp();
    tv.volumeUp();
    tv.channelUp();
    tv.channelUp();
    tv.showTVState();
}

//ң������
class Remote //����ΪTV����Ԫ�࣬����ֱ�ӷ���TV���е�˽������
{
private:
    TV * pTv;
public :
    Remote(TV * pTv)
    {
        this->pTv = pTv;
    }

    //����
    void volumeUp(void)
    {
        this->pTv->volumeUp();
    }
    void volumeDown(void)
    {
        this->pTv->volumeDown();
    }

    //Ƶ��
    void channelUp(void)
    {
        this->pTv->channelUp();
    }
    void channelDown(void)
    {
        this->pTv->channelDown();
    }

    //�����ػ�
    void onOrOff(void)
    {
        this->pTv->onOrOff();
    }

    //��������,ѡ������Ƶ��
    void setChannel(int num)
    {
        if(num > (pTv->maxChannel) || num < (TV::minChannel))
            return;
        else
            this->pTv->mChannel = num;
    }

    //��ʾ���ӻ���ʱ����Ϣ
    void showTvState(void)
    {
        this->pTv->showTVState();
    }

};

void test02()
{
    TV tv = TV();
    Remote remove = Remote(&tv);

    remove.onOrOff();
    remove.volumeUp();
    remove.volumeUp();
    remove.volumeUp();
    remove.channelUp();
    remove.channelUp();
    remove.showTvState();
    remove.setChannel(50);
    remove.showTvState();
}

int main(int argc, char *argv[])
{
    test01();

    test02();

    return 0;
}
