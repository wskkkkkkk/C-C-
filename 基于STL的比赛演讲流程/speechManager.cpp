#include"speechManager.h"
vector<pair<int, Player>> vfinal;
void speechManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void speechManager::clearRecord()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();


		//��ȡ�����¼
		this->getRecord();
		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}
speechManager::speechManager() {
	this->fileIsEmpty = true;
	getRecord();
}
void speechManager::menu() {
	cout << "******************************************************************" << endl;
	cout << "*************************��ӭ�μ��ݽ�����*************************" << endl;
	cout << "*************************1.��ʼ�ݽ�����***************************" << endl;
	cout << "*************************2.�鿴�����¼***************************" << endl;
	cout << "*************************3.��ձ�����¼***************************" << endl;
	cout << "*************************0.�˳���������***************************" << endl;
	cout << "******************************************************************" << endl;
	cout << endl;
}
void Inputvector(vector<int>&v) {
	for (int i = 10001; i <= 10012; i++) {
		v.push_back(i);
	}
}
void Inputmap(map<int,Player>& m) {
	Player p1("ѡ��A");
	Player p2("ѡ��B");
	Player p3("ѡ��C");
	Player p4("ѡ��D");
	Player p5("ѡ��E");
	Player p6("ѡ��F");
	Player p7("ѡ��G");
	Player p8("ѡ��H");
	Player p9("ѡ��I");
	Player p10("ѡ��J");
	Player p11("ѡ��K");
	Player p12("ѡ��L");
	m.insert(make_pair(10001, p1));
	m.insert(make_pair(10002, p2));
	m.insert(make_pair(10003, p3));
	m.insert(make_pair(10004, p4));
	m.insert(make_pair(10005, p5));
	m.insert(make_pair(10006, p6));
	m.insert(make_pair(10007, p7));
	m.insert(make_pair(10008, p8));
	m.insert(make_pair(10009, p9));
	m.insert(make_pair(10010, p10));
	m.insert(make_pair(10011, p11));
	m.insert(make_pair(10012, p12));
}
// ����һ��[min, max]��Χ�ڵ����С��
double generateRandomDouble(double min, double max) {
	static random_device rd;
	static mt19937 gen(rd()); // �� rd ��ʼ�� Mersenne Twister ����
	uniform_real_distribution<> dis(min, max);
	return dis(gen);
}
void speechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<pair<int, Player>>::iterator it = vfinal.begin(); it != vfinal.end(); it++) {
		ofs << (*it).first << "," << (*it).second.score<<",";
	}
	ofs << endl;
	this->fileIsEmpty = false;
	ofs.close();
}
void speechManager::getRecord() {
	int index = 0;
	fstream ifs;
	ifs.open("speech.csv", ios::in);
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		cout << "�ļ���ʧ��" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ�գ�" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	this->fileIsEmpty = false;

	ifs.putback(ch);//�������ȡ�ĵ����ַ� ������

	string data;
	while (ifs >> data) {
		vector<string> vRecord;
		//10010, 89.5, 10008, 86, 10007, 85.7,
		//cout << data << endl;
		int pos = -1;
		int start = 0;
		while(1){
	
			pos = data.find(",", start);
			if (pos == -1) {
				break;
			}
			string temp = data.substr(start, pos - start);
			vRecord.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, vRecord));
		index++;
	}
	ifs.close();
	/*for (map<int, vector<string>>::iterator it = this->m_Record.begin(); it != this->m_Record.end(); it++) {
		cout << (*it).first << " �ھ���" << (*it).second[0] <<" �÷֣�"<<(*it).second[1]<<endl;
	}*/
}
void speechManager::showRecord() {
	if (this->fileIsEmpty) {
		cout << "�ļ�Ϊ�գ�" << endl;

	}
	else {
		for (int i = 0; i < this->m_Record.size(); i++) {
			cout << "��" << i + 1 << "��"
				<< "  �ھ���ţ�" << this->m_Record[i][0] << "  �÷֣� " << this->m_Record[i][1] << " "
				<< "  �Ǿ���ţ�" << this->m_Record[i][2] << "  �÷֣� " << this->m_Record[i][3] << " "
				<< "  ������ţ�" << this->m_Record[i][4] << "  �÷֣� " << this->m_Record[i][5] << " " << endl;
		}
	}
	
	
	system("pause");
	system("cls");

}
class mySort {
public:
	bool operator()(pair<int, Player> &a, pair<int, Player>&b) {
		return a.second.score > b.second.score;
	}

};
vector<pair<int,Player>> getone(vector<int>& v, map<int, Player>& m) {
	map<int, Player>m1;
	for (int i = 0; i < 6; i++) {
		map<int,Player>::iterator pos = m.find(v[i]);
		m1.insert(make_pair(v[i], (*pos).second));
	}
	vector<pair<int, Player>> vm1(m1.begin(), m1.end());
	sort(vm1.begin(), vm1.end(), mySort());
	return vm1;
}
void showone(vector<pair<int,Player>> &vone) {
	cout << "--------��һ����ʽ������ʼ------------" << endl;
	cout << "��һС��������Σ�" << endl;
	for (vector<pair<int, Player>>::iterator it = vone.begin(); it != vone.end(); it++) {
		cout << "��ţ�" << (*it).first << "  ѡ�֣�" << (*it).second.m_Name << "  �ɼ���" << (*it).second.score << endl;
	}
	cout << endl;	
}

vector<pair<int, Player>> getonetwo(vector<int>& v, map<int, Player>& m) {
	map<int, Player>m1;
	for (int i = 6; i < 12; i++) {
		map<int, Player>::iterator pos = m.find(v[i]);
		m1.insert(make_pair(v[i], (*pos).second));
	}
	vector<pair<int, Player>> vm1(m1.begin(), m1.end());
	sort(vm1.begin(), vm1.end(), mySort());
	return vm1;
}
void showtwo(vector<pair<int, Player>>& vtwo) {
	cout << "�ڶ�С��������Σ�" << endl;
	for (vector<pair<int, Player>>::iterator it = vtwo.begin(); it != vtwo.end(); it++) {
		cout << "��ţ�" << (*it).first << "  ѡ�֣�" << (*it).second.m_Name << "  �ɼ���" << (*it).second.score << endl;
	}
	cout << endl;
	cout << "--------��һ�ֱ������------------" << endl;
}

void showtwoone(vector<pair<int, Player>>& vtwo) {
	cout << "--------�ڶ�����ʽ������ʼ------------" << endl;
	cout << "��һС��������Σ�" << endl;
	for (vector<pair<int, Player>>::iterator it = vtwo.begin(); it != vtwo.end(); it++) {
		cout << "��ţ�" << (*it).first << "  ѡ�֣�" << (*it).second.m_Name << "  �ɼ���" << (*it).second.score << endl;
	}
	cout << endl;
	cout << "--------�ڶ��ֱ������------------" << endl;
}

vector<pair<int, Player>> getvtwo(vector<pair<int, Player>>& voneone, vector<pair<int, Player>>& vonetwo) {
	vector<pair<int, Player>>vtwo;
	vector<pair<int, Player>>::iterator pos = voneone.begin();
	vector<pair<int, Player>>::iterator pos1 = vonetwo.begin();
	for (int i = 0; i < 3; i++) {
		vtwo.push_back(*pos);
		pos++;
	}
	for (int i = 0; i < 3; i++) {
		vtwo.push_back(*pos1);
		pos1++;
	}
	return vtwo;
}

vector<pair<int, Player>> getfinal(vector<pair<int, Player>> &vtwo) {
	vector<pair<int, Player>>vfinal;
	vector<pair<int, Player>>::iterator pos = vtwo.begin();
	for (int i = 0; i < 3; i++) {
		vfinal.push_back(*pos);
		pos++;
	}
	for (vector<pair<int, Player>>::iterator it = vfinal.begin(); it != vfinal.end(); it++) {
		cout << "��ţ�" << (*it).first << "  ѡ�֣�" << (*it).second.m_Name << "  �ɼ���" << (*it).second.score << endl;
	}
	return vfinal;
}

void speechManager::start() {
	cout << "��<< 1 >>�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "-----------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	
	map<int, Player>m;
	Inputmap(m);

	vector<int>v;
	Inputvector(v);

	random_shuffle(v.begin(), v.end());//��ǩ
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	
	for (map<int, Player>::iterator it = m.begin(); it != m.end(); it++) {
		vector<double>vd;
		for (int i = 0; i < 10; i++) {
			double dd = generateRandomDouble(70, 100);
			vd.push_back(dd);
		}
		double sum = accumulate(vd.begin(), vd.end(), 0);
		double avg = sum / vd.size();
		(*it).second.score = avg;
		vd.clear();
	}
	vector<pair<int, Player>>voneone = getone(v,m);
	showone(voneone);
	
	vector<pair<int, Player>>vonetwo = getonetwo(v, m);
	showtwo(vonetwo);
	
	system("pause");
	system("cls");

	cout << "��<< 2 >>�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "-----------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	vector<int>v1;
	for (int i = 0; i < 6; i++) {
		if (i < 3) {
			v1.push_back(voneone[i].first);
		}
		else {
			v1.push_back(vonetwo[i-3].first);
		}
	}
	random_shuffle(v1.begin(), v1.end());//�ڶ��ֳ�ǩ
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << " ";
	}
	vector<pair<int, Player>>vtwo = getvtwo(voneone, vonetwo);
	system("pause");

	for (vector<pair<int, Player>>::iterator it = vtwo.begin(); it != vtwo.end(); it++) {
		vector<double>vd;
		for (int i = 0; i < 10; i++) {
			double dd = generateRandomDouble(70, 100);
			vd.push_back(dd);
		}
		double sum = accumulate(vd.begin(), vd.end(), 0);
		double avg = sum / vd.size();
		(*it).second.score = avg;
		vd.clear();
	}
	sort(vtwo.begin(), vtwo.end(), mySort());
	showtwoone(vtwo);
	
	system("pause");
	cout << "--------�ڶ��ֽ���ѡ����Ϣ���£�------------" << endl;
	vfinal = getfinal(vtwo);

	system("pause");
	system("cls");
	cout << "��¼�Ѿ�������ϣ�" << endl;
	cout << "���������ϣ�" << endl;
	saveRecord();
	getRecord();
	system("pause");
}