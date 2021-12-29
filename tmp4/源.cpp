class Score
{
public:
	Score(int n = 1, int m = 0, int e = 0, int p = 0)
	{
		mNum = n;
		mMath = m;
		mEnglish = e;
		mProgramming = p;
	}
	double InputScore(int n, int m, int e, int p)  //����ѧ�ź͸��Ƴɼ������Ҽ���ƽ���ɼ�
	{
		mNum = n;
		mMath = m;
		mEnglish = e;
		mProgramming = p;
		return (mMath + mEnglish + mProgramming) / 3;
	}

	void ShowScore()     //���ѧ�ź͸��Ƴɼ�
	{
		cout << "Number:" << mNum << "\t" << "Math:" << mMath << "\t\t" << "English:" << mEnglish << "\t" << "Programming:" << mProgramming;
		cout << "\n" << "the student's average score is :" << InputScore(mNum, mMath, mEnglish, mProgramming) << "\n";
	}
	~Score()
	{

	}
private:
	int mNum;
	int mMath;
	int mEnglish;
	int mProgramming;

};
int main()
{
	int c, n, m, e, p;
	cout << "count:";
	cin >> c; //����
	Score* arr = new Score[c];


	for (int i = 0; i < c; i++)
	{
		cout << "Number:";
		cin >> n;
		cout << "Math:";
		cin >> m;
		cout << "English:";
		cin >> e;
		cout << "Programming:";
		cin >> p;
		arr[i].InputScore(n, m, e, p);
	}

	for (int i = 0; i < c; i++)
	{
		arr[i].ShowScore();
	}
	delete[]arr;
}