#include <iostream>
#include <tuple>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//typedef tuple<string, int, int, int> Student;
struct Student
{
	string name;
	int korean;
	int english;
	int math;
};

int n;
//Student student[100003];
vector<Student> vec;
/*
bool cmp(Student &s1, Student &s2)
{
	if (get<1>(s1) != get<1>(s2))
	{
		return get<1>(s1) > get<1>(s2);
	}
	if (get<2>(s1) != get<2>(s2))
	{
		return get<2>(s1) < get<2>(s2);
	}
	if (get<3>(s1) != get<3>(s2))
	{
		return get<3>(s1) > get<3>(s2);
	}
	if (get<0>(s1) != get<0>(s2))
	{
		return get<0>(s1) < get<0>(s2);
	}
}
*/
bool cmp(Student &s1, Student &s2)
{
	/*
	if (s1.korean != s2.korean)
	{
		return s1.korean > s2.korean;
	}
	if (s1.english != s2.english)
	{
		return s1.english < s2.english;
	}
	if (s1.math != s2.math)
	{
		return s1.math > s2.math;
	}
	if (s1.name != s2.name)
	{
		return s1.name < s2.name;
	}
	*/
	if (s1.korean != s2.korean)
	{
		return s1.korean > s2.korean;
	}
	else if (s1.english != s2.english)
	{
		return s1.english < s2.english;
	}
	else if (s1.math != s2.math)
	{
		return s1.math > s2.math;
	}
	else
	{
		return s1.name < s2.name;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		int a, b, c;
		cin >> s >> a >> b >> c;
		//student[i] = make_tuple(a * -1, b, c * -1, s);
		//vec.push_back(make_tuple(s, a, b, c));
		vec.push_back({s, a, b, c});
	}
	//sort(student, student + n, cmp);
	sort(vec.begin(), vec.end(), cmp);
	/*
	for (int i = 0; i < n; i++)
	{
		cout << student[i].name << endl;
	}
	*/
	for (Student student : vec)
	{
		cout << student.name << endl;
	}
	return 0;
}