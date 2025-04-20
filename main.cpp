#include"student.h"
#include "course.h"

int main() {
    vector<Student> students;
    vector<Course> courses;
    int choice;

    while (true) {
        cout << "\n===== 學生選課系統 =====\n";
        cout << "1. 新增學生\n";
        cout << "2. 新增課程（含人數上限）\n";
        cout << "3. 學生加選課程\n";
        cout << "4. 學生退選課程\n";
        cout << "5. 顯示學生課表\n";
        cout << "6. 顯示課程學生名單\n";
        cout << "7. 離開\n";
        cout << "8. 顯示所有課程\n";
        cout << "請輸入選項：";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string id, name;
            cout << "輸入學生ID：";
            getline(cin, id);
            cout << "輸入學生姓名：";
            getline(cin, name);
            students.emplace_back(id, name);
            cout << " 學生已新增。\n";
        }
        else if (choice == 2) {
            string code, title;
            int cap;
            cout << "輸入課程代碼：";
            getline(cin, code);
            cout << "輸入課程名稱：";
            getline(cin, title);
            cout << "輸入人數上限：";
            cin >> cap;
            cin.ignore();
            courses.emplace_back(code, title, cap);
            cout << "✅ 課程已新增。\n";
        }
        else if (choice == 3) {
            string sid, ccode;
            cout << "輸入學生ID：";
            getline(cin, sid);
            cout << "輸入課程代碼：";
            getline(cin, ccode);

            auto sit = find_if(students.begin(), students.end(), [&](Student& s) {
                return s.getId() == sid;
                });

            auto cit = find_if(courses.begin(), courses.end(), [&](Course& c) {
                return c.getCode() == ccode;
                });

            if (sit != students.end() && cit != courses.end()) {
                sit->enroll(&(*cit));
            }
            else {
                cout << "❌ 找不到該學生或課程。\n";
            }
        }
        else if (choice == 4) {
            string sid, ccode;
            cout << "輸入學生ID：";
            getline(cin, sid);
            cout << "輸入課程代碼：";
            getline(cin, ccode);

            auto sit = find_if(students.begin(), students.end(), [&](Student& s) {
                return s.getId() == sid;
                });

            auto cit = find_if(courses.begin(), courses.end(), [&](Course& c) {
                return c.getCode() == ccode;
                });

            if (sit != students.end() && cit != courses.end()) {
                sit->drop(&(*cit));
            }
            else {
                cout << "❌ 找不到該學生或課程。\n";
            }
        }
        else if (choice == 5) {
            string sid;
            cout << "輸入學生ID：";
            getline(cin, sid);
            auto sit = find_if(students.begin(), students.end(), [&](Student& s) {
                return s.getId() == sid;
                });
            if (sit != students.end()) {
                sit->printCourses();
            }
            else {
                cout << "❌ 找不到該學生。\n";
            }
        }
        else if (choice == 6) {
            string ccode;
            cout << "輸入課程代碼：";
            getline(cin, ccode);
            auto cit = find_if(courses.begin(), courses.end(), [&](Course& c) {
                return c.getCode() == ccode;
                });
            if (cit != courses.end()) {
                cit->printStudents();
            }
            else {
                cout << "❌ 找不到該課程。\n";
            }
        }
        else if (choice == 7) {
            cout << "👋 感謝使用，再見！\n";
            break;
        }
        else if (choice == 8) {
            if (courses.empty()) {
                cout << "⚠️ 尚未建立任何課程。\n";
            }
            else {
                cout << "📚 所有課程清單：\n";
                for (const auto& c : courses) {
                    cout << " - " << c.getCode() << ": " << c.getTitle()
                        << "（已修人數：" << c.getEnrolledCount()
                        << " / 上限：" << c.getCapacity() << "）\n";
                }
            }
        }

        else {
            cout << "⚠️ 無效的選項，請重新輸入。\n";
        }
    }

    return 0;
}
