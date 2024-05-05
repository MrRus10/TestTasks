#include <iostream>
#include <fstream>
#include <string>
#include "dependencies/include/nlohmann/json.hpp"

using namespace std;

int main() {
	nlohmann::json obj_json1;
	nlohmann::json obj_json2;

	fstream fileInput1;
	fileInput1.open("values.json");
	fileInput1 >> obj_json1;
	//cout << obj_json1 << endl;

	vector<int> ids1;
	vector<string> values1;

	for (int i = 0; i < obj_json1["values"].size(); ++i) {
		ids1.push_back(obj_json1["values"][i]["id"]);
		values1.push_back(obj_json1["values"][i]["value"]);
	}

	for (int i = 0; i < obj_json1["values"].size(); ++i) {
		cout << ids1[i] << " "s << values1[i] << endl;
	}
	cout << endl;

	fileInput1.close();

	fstream fileInput2;
	fileInput2.open("tests.json");
	fileInput2 >> obj_json2;

	vector<int> ids2;
	vector<string> titles2;
	vector<string> values2;

	for (int i = 0; i < obj_json2["tests"].size(); ++i) {
		ids2.push_back(obj_json2["tests"][i]["id"]);
		titles2.push_back(obj_json2["tests"][i]["title"]);
		values2.push_back(obj_json2["tests"][i]["value"]);
	}

	for (int i = 0; i < obj_json2["tests"].size(); ++i) {
		cout << ids2[i] << " "s << titles2[i] << " "s << values2[i] << endl;
	}

	fileInput2.close();
}