#include <iostream>
#include <utility>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned u;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<string, string> pss;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <double> vd;
typedef vector <char> vc;
typedef vector <string> vs;
typedef vector <pii> vpii;
typedef vector <psi> vpsi;
typedef vector <pss> vpss;
typedef vector <vi> vvi;
typedef unsigned long long ull;
#define fff(itr, lim) for (int itr = 0; itr < int(lim); ++itr)
#define ffff(itr, lim) for (int itr = 1; itr <= int(lim); ++itr)
#define rrr(itr, lim) for (int itr = int(lim)-1; itr > -1; --itr)
#define wn(n) while (n--)
#define s1(n) scanf("%d", &n)
#define s2(n, m) scanf("%d %d", &n, &m)
#define s3(n, m, k) scanf("%d %d %d", &n, &m, &k)
#define sv(n, v) fff(i, n) scanf("%d", &v[i])
#define pr(n) printf("%d", n)
#define pr2(n, m) printf("%d %d", n, m)
#define prn(n) printf("%d\n", n)
#define prs(n) printf("%d ", n)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ull oo = (ll)1e9;
const int mx = (int)1e3 + 5;

string tpath{"./database/tasks.txt"};


int new_id () {
    /*
     * this function returns a new id from the file id.txt in the database
     */

    int id;
    string path{"./database/id.txt"};

    ifstream id_file(path);
    id_file >> id;
    id_file.close();

    fstream _uid(path, (ios::out | ios::trunc));
    _uid << (id+1);
    _uid.close();

    return id;
}


void append_to (string line) {
    /*
     * this function takes a path to a file and add line to the end of it
     */

    ofstream file(tpath, (ios::out | ios::app));
    file << line;
    file << '\n';
    file.close();
}


bool remove_from(int id) {
    /*
     * this function takes the path to a file and id
     * it removes the line that starts with id == the given id
     * it skip == true : it skips the first line
     */


    ifstream file(tpath); string line; int _id; vs lines; bool found{};

    while (getline(file, line)) {

        istringstream s(line); s >> _id;
        if (id != _id) lines.push_back(line);
        if (id == _id) found = true;

    }

    file.close();

    if (!found)
        return false;

    fstream file_to_out(tpath, (ios::out | ios::trunc));

    fff(i, lines.size()) {
        file_to_out << lines[i];
        file_to_out << '\n';
    }

    file_to_out.close();

    return true;
}




class task {
private:
    int id, priority, period;
    bool edited, done, created;
    string name;
public:
    task(): edited(false), created(false), done(false) {

    }

    task(int _id, int _pr, int _period, string _name) // quering from database
    : id(_id), priority(_pr), name(std::move(_name)), period(_period), edited(false), created(false), done(false) {

    }

    task(int _pr, string _name, int _period) // creating a task
            : id(new_id()), priority(_pr), name(std::move(_name)), period(_period), edited(false), created(true), done(false) {
        cout << "You created task : " << name << endl;
    }

    int get_id() {
        return id;
    }

    int get_period() {
        return period;
    }

    int get_priority() {
        return priority;
    }

    string get_name() {
        return name;
    }

    void update() {
        priority ++;
    }

    void show () {
        cout << "This task should take " << period << "h, and should be done (the inverse priority) before " << priority << " days: " << name << endl;
    }

    bool operator > (task *_task) const {
        if (_task == nullptr)
            return true;

        return priority > _task->get_priority();
    }

    bool operator >= (task *_task) const {
        if (_task == nullptr)
            return true;

        return priority >= _task->get_priority();
    }

    bool operator < (task *_task) {
        if (_task == nullptr)
            return false;

        return priority > _task->get_priority();
    }

    bool operator <= (task *_task) const {
        if (_task == nullptr)
            return false;

        return priority <= _task->get_priority();
    }

    bool operator == (task *_task) const {
        if (_task == nullptr)
            return false;
        return priority == _task->get_priority();
    }

    ~task () {
        //
    }
};


struct LessThanByAge
{
    bool operator()(task *_task1, task *_task2)
    {
        return _task1->operator<(_task2);
    }
};


class calender {
private:
    priority_queue <task*, vector<task*>, LessThanByAge> tasks;
public:
    calender () {
        ifstream file(tpath);
        string name; int id, pr, per;
        while (file.peek() != EOF) {
            file >> id >> pr >> per;
            file.ignore(1000, '\n');
            getline(file, name);
            tasks.push(new task(id, pr, per, name));
        }
    }

    void add_task(int priority, int per, string name) {
        tasks.push(new task(priority, std::move(name), per));
    }

    void get_task() {
        if (!tasks.empty())
            tasks.top()->show();
        else
            cout << "enjoy you don't have taskes to do" << endl;
    }

    void done() {
        if (tasks.empty()) {
            cout << "an error happend" << endl;
            return;
        }

        task *_task = tasks.top();
        tasks.pop();

        delete _task;

        cout << "awesome work, keep going" << endl;
    }

    void update() {
        vector <task*> _t;
        while (!tasks.empty()) {
            _t.push_back(tasks.top());
            tasks.pop();
        }

        while (!_t.empty()) {
            _t.back()->update();
            tasks.push(_t.back());
            _t.pop_back();
        }
    }

    void show_all() {
        if (tasks.empty()) {
            cout << "enjoy you don't have taskes to do" << endl;
            return;
        }

        vector <task*> _t;
        while (!tasks.empty()) {
            _t.push_back(tasks.top());
            tasks.pop();
        }

        fff(i, _t.size()) {
            _t[i]->show();
            tasks.push(_t[i]);
        }
    }

    ~calender() {
        fstream file_to_out(tpath, (ios::out | ios::trunc));
        while (!tasks.empty()) {
            task *_task = tasks.top();
            string line = to_string(_task->get_id()) + ' ' + to_string(_task->get_priority())
                    + ' ' + to_string(_task->get_period()) + '\n' + _task->get_name();

            file_to_out << line << '\n';
            tasks.pop();

            delete _task;


        }
        file_to_out.close();
    }
};


int main() {

    calender today;

    char c{};

    do {

        cout << " ********* please select ********** " << endl;
        cout << "        1: update the dates" << endl;
        cout << "        2: get a task      " << endl;
        cout << "        3: did a task      " << endl;
        cout << "        4: add a task      " << endl;
        cout << "        5: show all tasks  " << endl;
        cout << "        0: get out         " << endl;
        cout << " >>> ";
        cin >> c;

        switch (c) {

            case '1': {
                today.update();
                cout << "you updated the dates of the tasks" << endl;
                break;
            }

            case '2': {
                today.get_task();
                break;
            }

            case '3': {
                today.done();
                break;
            }

            case '4': {
                int priority, period;
                string name;
                cout << "please inter the number of days before the deadline, the time that this task is to take, name\n >>> ";
                cin >> priority >> period;
                getline(cin, name);
                today.add_task(priority, period, name);
                break;
            }

            case '5': {
                today.show_all();
                break;
            }

            case '0': {
                cout << "thank you for using my app" << endl;
                break;
            }

            default:
                cout << "sorry you must have done a mistake" << endl;

        }
    } while (c != '0');

    return 0;
}