/*
 * ============================================================================
 * BÀI TẬP LỚN: QUẢN LÝ THÔNG TIN KHÓA HỌC
 * Môn học: Nhập môn Lập trình
 * Đề tài 5: Quản lý thông tin khóa học
 * ============================================================================
 * File: main.cpp
 * Mô tả: File chính chứa hàm main và các chức năng xử lý menu
 * Phiên bản: Vector (Mảng động) - Sử dụng std::vector thay vì Linked List
 * ============================================================================
 * Cấu trúc dự án:
 *   - Course.h / Course.cpp       : Lớp Khóa học
 *   - CourseList.h / .cpp         : Lớp quản lý danh sách (dùng vector)
 *   - Utils.h / Utils.cpp         : Các hàm tiện ích (giao diện)
 *   - main.cpp                    : File chính
 * ============================================================================
 */

#include <iostream>
#include <limits>
#include "Course.h"
#include "CourseList.h"
#include "Utils.h"

using namespace std;

// ============================================================================
// PHẦN 1: CÁC HÀM CHỨC NĂNG CHÍNH
// ============================================================================

/*
 * Hàm: addNewCourse(CourseList& list)
 * Mục đích: Thêm một khóa học mới vào danh sách
 * Tham số: list - Tham chiếu đến danh sách khóa học
 */
void addNewCourse(CourseList& list) {
    clearScreen();
    printHeader("THEM KHOA HOC MOI");

    string courseId, courseName;
    int credits, studentCount;

    // ========================================================================
    // Bước 1: Nhập và kiểm tra mã khóa học (không được trùng)
    // ========================================================================
    while (true) {
        cout << "    Nhap ma khoa hoc: ";
        getline(cin, courseId);
        
        if (courseId.empty()) {
            cout << "    [!] Loi: Ma khoa hoc khong duoc de trong!\n";
            continue;
        }
        
        // Kiểm tra trùng lặp bằng hàm isIdExist của CourseList
        if (list.isIdExist(courseId)) {
            cout << "    [!] Loi: Ma khoa hoc '" << courseId << "' da ton tai!\n";
            cout << "    Vui long nhap ma khac.\n\n";
            continue;
        }
        
        break;
    }

    // ========================================================================
    // Bước 2: Nhập tên khóa học
    // ========================================================================
    while (true) {
        cout << "    Nhap ten khoa hoc: ";
        getline(cin, courseName);
        
        if (courseName.empty()) {
            cout << "    [!] Loi: Ten khoa hoc khong duoc de trong!\n";
            continue;
        }
        break;
    }

    // ========================================================================
    // Bước 3: Nhập và kiểm tra số tín chỉ (phải > 0)
    // ========================================================================
    while (true) {
        cout << "    Nhap so tin chi (> 0): ";
        
        if (!(cin >> credits)) {
            cout << "    [!] Loi: Vui long nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        if (credits <= 0) {
            cout << "    [!] Loi: So tin chi phai lon hon 0!\n";
            continue;
        }
        
        break;
    }

    // ========================================================================
    // Bước 4: Nhập và kiểm tra số lượng sinh viên (phải >= 0)
    // ========================================================================
    while (true) {
        cout << "    Nhap so luong sinh vien dang ky (>= 0): ";
        
        if (!(cin >> studentCount)) {
            cout << "    [!] Loi: Vui long nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        if (studentCount < 0) {
            cout << "    [!] Loi: So luong sinh vien phai >= 0!\n";
            continue;
        }
        
        break;
    }

    // ========================================================================
    // Bước 5: Tạo đối tượng Course và thêm vào vector
    // SO SÁNH: Với vector, chỉ cần gọi push_back()
    //          Không cần tạo Node, không cần cập nhật con trỏ prev/next
    // ========================================================================
    Course newCourse(courseId, courseName, credits, studentCount);
    list.addCourse(newCourse);

    cout << "\n";
    cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
    cout << "    ║     [✓] DA THEM KHOA HOC THANH CONG!                         ║\n";
    cout << "    ╚══════════════════════════════════════════════════════════════╝\n";

    pauseScreen();
}

/*
 * Hàm: displayAllCourses(CourseList& list)
 * Mục đích: Hiển thị tất cả khóa học trong danh sách dạng bảng
 * 
 * SO SÁNH CÁCH DUYỆT VECTOR VỚI LINKED LIST:
 * - Linked List: Dùng con trỏ, current = current->next
 * - Vector: Dùng vòng lặp for với chỉ số hoặc for-each
 */
void displayAllCourses(const CourseList& list) {
    clearScreen();
    printHeader("DANH SACH TAT CA KHOA HOC");

    if (list.isEmpty()) {
        cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
        cout << "    ║          [!] Danh sach khoa hoc hien dang trong!             ║\n";
        cout << "    ╚══════════════════════════════════════════════════════════════╝\n";
        pauseScreen();
        return;
    }

    cout << "    >> Tong so khoa hoc: " << list.getSize() << "\n\n";

    printTableHeader();

    // ========================================================================
    // DUYỆT VECTOR BẰNG FOR-EACH (Range-based for loop)
    // Cú pháp: for (const Course& course : list.getAll())
    // - Đơn giản, dễ đọc hơn so với dùng con trỏ trong linked list
    // - Không cần quan tâm đến prev/next
    // ========================================================================
    for (const Course& course : list.getAll()) {
        printTableRow(course);
    }

    printTableFooter();

    pauseScreen();
}

/*
 * Hàm: searchCourse(CourseList& list)
 * Mục đích: Tìm kiếm khóa học theo mã
 */
void searchCourse(const CourseList& list) {
    clearScreen();
    printHeader("TIM KIEM KHOA HOC");

    if (list.isEmpty()) {
        cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
        cout << "    ║          [!] Danh sach khoa hoc hien dang trong!             ║\n";
        cout << "    ╚══════════════════════════════════════════════════════════════╝\n";
        pauseScreen();
        return;
    }

    string searchId;
    cout << "    Nhap ma khoa hoc can tim: ";
    getline(cin, searchId);

    // Tìm kiếm - trả về chỉ số thay vì con trỏ như linked list
    int index = list.findById(searchId);

    if (index != -1) {
        // Tìm thấy - Lấy khóa học qua chỉ số (O(1) với vector)
        cout << "\n";
        cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
        cout << "    ║              [✓] TIM THAY KHOA HOC!                          ║\n";
        cout << "    ╚══════════════════════════════════════════════════════════════╝\n";
        cout << "\n";
        
        printTableHeader();
        printTableRow(list.getCourse(index));
        printTableFooter();
    } else {
        cout << "\n";
        cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
        cout << "    ║     [!] KHONG TIM THAY khoa hoc voi ma da nhap!              ║\n";
        cout << "    ╚══════════════════════════════════════════════════════════════╝\n";
    }

    pauseScreen();
}

/*
 * Hàm: showMaxStudentCourses(CourseList& list)
 * Mục đích: Hiển thị (các) khóa học có số SV đăng ký NHIỀU NHẤT
 */
void showMaxStudentCourses(const CourseList& list) {
    clearScreen();
    printHeader("THONG KE: KHOA HOC CO NHIEU SV NHAT");

    if (list.isEmpty()) {
        cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
        cout << "    ║          [!] Danh sach khoa hoc hien dang trong!             ║\n";
        cout << "    ╚══════════════════════════════════════════════════════════════╝\n";
        pauseScreen();
        return;
    }

    int maxCount = list.getMaxStudentCount();
    
    cout << "    >> So luong sinh vien dang ky nhieu nhat: " << maxCount << "\n\n";
    cout << "    >> Cac khoa hoc co so SV dang ky nhieu nhat:\n\n";

    printTableHeader();

    // Duyệt vector và in các khóa học có số SV = max
    int count = 0;
    for (const Course& course : list.getAll()) {
        if (course.getStudentCount() == maxCount) {
            printTableRow(course);
            count++;
        }
    }

    printTableFooter();
    
    cout << "\n    >> Tong cong: " << count << " khoa hoc\n";

    pauseScreen();
}

/*
 * Hàm: showMinStudentCourses(CourseList& list)
 * Mục đích: Hiển thị (các) khóa học có số SV đăng ký ÍT NHẤT
 */
void showMinStudentCourses(const CourseList& list) {
    clearScreen();
    printHeader("THONG KE: KHOA HOC CO IT SV NHAT");

    if (list.isEmpty()) {
        cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
        cout << "    ║          [!] Danh sach khoa hoc hien dang trong!             ║\n";
        cout << "    ╚══════════════════════════════════════════════════════════════╝\n";
        pauseScreen();
        return;
    }

    int minCount = list.getMinStudentCount();
    
    cout << "    >> So luong sinh vien dang ky it nhat: " << minCount << "\n\n";
    cout << "    >> Cac khoa hoc co so SV dang ky it nhat:\n\n";

    printTableHeader();

    int count = 0;
    for (const Course& course : list.getAll()) {
        if (course.getStudentCount() == minCount) {
            printTableRow(course);
            count++;
        }
    }

    printTableFooter();
    
    cout << "\n    >> Tong cong: " << count << " khoa hoc\n";

    pauseScreen();
}

// ============================================================================
// PHẦN 2: HÀM MAIN - ĐIỂM BẮT ĐẦU CHƯƠNG TRÌNH
// ============================================================================

int main() {
    // Tạo đối tượng CourseList - nội bộ sử dụng std::vector
    CourseList courseList;
    
    int choice;
    
    // ========================================================================
    // Thêm dữ liệu mẫu để test
    // ========================================================================
    courseList.addCourse(Course("CS101", "Nhap mon Lap trinh", 3, 120));
    courseList.addCourse(Course("CS102", "Cau truc Du lieu", 4, 95));
    courseList.addCourse(Course("CS201", "Lap trinh Huong doi tuong", 3, 85));
    courseList.addCourse(Course("CS202", "Co so Du lieu", 4, 120));
    courseList.addCourse(Course("CS301", "Toan roi rac", 3, 75));

    // ========================================================================
    // Vòng lặp menu chính
    // ========================================================================
    do {
        clearScreen();
        printMainMenu();
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                addNewCourse(courseList);
                break;
                
            case 2:
                displayAllCourses(courseList);
                break;
                
            case 3:
                searchCourse(courseList);
                break;
                
            case 4:
                showMaxStudentCourses(courseList);
                break;
                
            case 5:
                showMinStudentCourses(courseList);
                break;
                
            case 0:
                showExitMessage();
                break;
                
            default:
                cout << "\n    [!] Lua chon khong hop le! Vui long nhap lai (0-5).\n";
                cout << "    Nhan Enter de tiep tuc...";
                cin.get();
                break;
        }
        
    } while (choice != 0);

    return 0;
}

/*
 * ============================================================================
 * HƯỚNG DẪN BIÊN DỊCH VÀ CHẠY
 * ============================================================================
 * 
 * g++ -o QuanLyKhoaHoc main.cpp Course.cpp CourseList.cpp Utils.cpp -std=c++11
 * ./QuanLyKhoaHoc
 * 
 * Hoặc sử dụng Makefile:
 *   make
 *   ./QuanLyKhoaHoc
 * 
 * ============================================================================
 * SO SÁNH VECTOR VÀ DANH SÁCH LIÊN KẾT ĐÔI
 * ============================================================================
 * 
 * | Thao tác           | Vector      | Linked List |
 * |--------------------|-------------|-------------|
 * | Truy cập [i]       | O(1)        | O(n)        |
 * | Thêm cuối          | O(1)*       | O(1)        |
 * | Thêm đầu/giữa      | O(n)        | O(1)        |
 * | Xóa cuối           | O(1)        | O(1)        |
 * | Xóa đầu/giữa       | O(n)        | O(1)        |
 * | Tìm kiếm           | O(n)        | O(n)        |
 * | Bộ nhớ             | Liền kề     | Phân tán    |
 * 
 * (*) O(1) trung bình (amortized), có thể O(n) khi phải mở rộng
 * 
 * ============================================================================
 */
