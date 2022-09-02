#include <iostream>

using namespace std;

//电视类
class TV
{
friend class Remote;
private :
    int mState; // 状态
    int mVolume; //音量
    int mChannel; //频道
    enum { On,Off}; //状态枚举
    enum{ minVol, maxVol=100}; //音量枚举
    enum{ minChannel = 1, maxChannel = 255}; //频道枚举
public :
    TV()
    {
        this->mState = Off;
        this->mVolume = minVol;
        this->mChannel = minChannel;
    }

    //开关电视
    void onOrOff(void)
    {
        this->mState = (this->mState == On ? Off:On);
    }

    //加大音量
    void volumeUp(void)
    {
        if(this->mVolume >= maxVol)
            return;
        this->mVolume++;
    }
    //减小音量
    void volumeDown(void)
    {
        if(this->mVolume <= minVol)
            return;
        this->mVolume--;
    }

    //增加频道
    void channelUp(void)
    {
        if(this->mChannel >= maxChannel)
            return;
        this->mChannel++;
    }
    //减少频道
    void channelDown(void)
    {
        if(this->mChannel <= minChannel)
            return;
        this->mChannel--;
    }

    //显示电视机的状态
    void showTVState(void)
    {
        cout << "电视机状态为 : " << (this->mState == On ? "开机" : "关机") << endl;
        cout << "电视机的音量为 : " << this->mVolume << endl;
        cout << "电视机的频道 : " << this->mChannel << endl;
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

//遥控器类
class Remote //设置为TV的有元类，可以直接访问TV类中的私有数据
{
private:
    TV * pTv;
public :
    Remote(TV * pTv)
    {
        this->pTv = pTv;
    }

    //音量
    void volumeUp(void)
    {
        this->pTv->volumeUp();
    }
    void volumeDown(void)
    {
        this->pTv->volumeDown();
    }

    //频道
    void channelUp(void)
    {
        this->pTv->channelUp();
    }
    void channelDown(void)
    {
        this->pTv->channelDown();
    }

    //开、关机
    void onOrOff(void)
    {
        this->pTv->onOrOff();
    }

    //新增功能,选择、设置频道
    void setChannel(int num)
    {
        if(num > (pTv->maxChannel) || num < (TV::minChannel))
            return;
        else
            this->pTv->mChannel = num;
    }

    //显示电视机此时的信息
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
