/*
 * ============================================================================
 * File: CourseList.cpp
 * Mô tả: Implementation của lớp CourseList sử dụng std::vector
 * Phiên bản: Vector (Mảng động)
 * ============================================================================
 */

#include "CourseList.h"

// ============================================================================
// Constructor - Khởi tạo danh sách rỗng
// Vector tự động khởi tạo rỗng, không cần làm gì thêm
// ============================================================================
CourseList::CourseList() {
    // Vector được khởi tạo mặc định là rỗng
}

// ============================================================================
// Destructor - Vector tự động giải phóng bộ nhớ
// Không cần xử lý thủ công như danh sách liên kết
// ============================================================================
CourseList::~CourseList() {
    // Vector tự động gọi destructor cho các phần tử và giải phóng bộ nhớ
}

// ============================================================================
// Phương thức: isEmpty()
// Mục đích: Kiểm tra danh sách có rỗng không
// Trả về: true nếu rỗng, false nếu có ít nhất 1 khóa học
// 
// GIẢI THÍCH:
// - Sử dụng hàm empty() có sẵn của vector
// - Độ phức tạp: O(1)
// ============================================================================
bool CourseList::isEmpty() const {
    return courses.empty();
}

// ============================================================================
// Phương thức: getSize()
// Mục đích: Lấy số lượng khóa học trong danh sách
// Trả về: Số nguyên là số lượng khóa học
// 
// GIẢI THÍCH:
// - Sử dụng hàm size() có sẵn của vector
// - Độ phức tạp: O(1)
// ============================================================================
int CourseList::getSize() const {
    return courses.size();
}

// ============================================================================
// Phương thức: isIdExist(string id)
// Mục đích: Kiểm tra mã khóa học đã tồn tại trong danh sách chưa
// Tham số: id - Mã khóa học cần kiểm tra
// Trả về: true nếu đã tồn tại, false nếu chưa
// 
// GIẢI THÍCH LOGIC DUYỆT VECTOR:
// - Sử dụng vòng lặp for-each (range-based for loop)
// - Duyệt qua từng phần tử trong vector
// - So sánh mã khóa học với mã cần tìm
// - Độ phức tạp: O(n) với n là số phần tử
// ============================================================================
bool CourseList::isIdExist(string id) const {
    // Duyệt qua toàn bộ vector bằng vòng lặp for-each
    for (const Course& course : courses) {
        if (course.getCourseId() == id) {
            return true;  // Tìm thấy - mã đã tồn tại
        }
    }
    return false;  // Duyệt hết mà không tìm thấy
}

// ============================================================================
// Phương thức: addCourse(Course course)
// Mục đích: Thêm một khóa học mới vào CUỐI danh sách
// Tham số: course - Đối tượng khóa học cần thêm
// 
// GIẢI THÍCH LOGIC THÊM PHẦN TỬ VÀO VECTOR:
// - Sử dụng hàm push_back() của vector
// - Tự động mở rộng kích thước nếu cần
// - Độ phức tạp: O(1) trung bình (amortized)
// 
// SO SÁNH VỚI DANH SÁCH LIÊN KẾT ĐÔI:
// - Linked List: Phải tạo Node mới, cập nhật con trỏ prev/next, cập nhật tail
// - Vector: Chỉ cần gọi push_back(), đơn giản hơn nhiều
// ============================================================================
void CourseList::addCourse(Course course) {
    // Thêm khóa học vào cuối vector
    // Vector tự động quản lý bộ nhớ
    courses.push_back(course);
}

// ============================================================================
// Phương thức: findById(string id)
// Mục đích: Tìm kiếm khóa học theo mã
// Tham số: id - Mã khóa học cần tìm
// Trả về: Chỉ số của khóa học trong vector, -1 nếu không tìm thấy
// 
// GIẢI THÍCH:
// - Duyệt qua vector bằng chỉ số
// - Trả về chỉ số khi tìm thấy (khác với linked list trả về con trỏ)
// - Độ phức tạp: O(n)
// ============================================================================
int CourseList::findById(string id) const {
    // Duyệt qua vector bằng chỉ số
    for (int i = 0; i < (int)courses.size(); i++) {
        if (courses[i].getCourseId() == id) {
            return i;  // Tìm thấy - trả về chỉ số
        }
    }
    return -1;  // Không tìm thấy
}

// ============================================================================
// Phương thức: getCourse(int index)
// Mục đích: Lấy khóa học tại vị trí index
// Tham số: index - Chỉ số trong vector
// Trả về: Đối tượng Course tại vị trí đó
// 
// GIẢI THÍCH:
// - Truy cập ngẫu nhiên qua chỉ số - ưu điểm của vector
// - Độ phức tạp: O(1) - nhanh hơn linked list O(n)
// ============================================================================
Course CourseList::getCourse(int index) const {
    return courses[index];
}

// ============================================================================
// Phương thức: getMaxStudentCount()
// Mục đích: Tìm số lượng sinh viên đăng ký nhiều nhất
// Trả về: Số lượng sinh viên lớn nhất, -1 nếu danh sách rỗng
// 
// GIẢI THÍCH:
// - Khởi tạo max bằng phần tử đầu tiên
// - Duyệt qua các phần tử còn lại, cập nhật max nếu tìm thấy giá trị lớn hơn
// ============================================================================
int CourseList::getMaxStudentCount() const {
    if (isEmpty()) return -1;

    int maxCount = courses[0].getStudentCount();
    
    // Duyệt từ phần tử thứ 2 đến cuối
    for (int i = 1; i < (int)courses.size(); i++) {
        if (courses[i].getStudentCount() > maxCount) {
            maxCount = courses[i].getStudentCount();
        }
    }

    return maxCount;
}

// ============================================================================
// Phương thức: getMinStudentCount()
// Mục đích: Tìm số lượng sinh viên đăng ký ít nhất
// Trả về: Số lượng sinh viên nhỏ nhất, -1 nếu danh sách rỗng
// ============================================================================
int CourseList::getMinStudentCount() const {
    if (isEmpty()) return -1;

    int minCount = courses[0].getStudentCount();
    
    // Duyệt từ phần tử thứ 2 đến cuối
    for (int i = 1; i < (int)courses.size(); i++) {
        if (courses[i].getStudentCount() < minCount) {
            minCount = courses[i].getStudentCount();
        }
    }

    return minCount;
}

// ============================================================================
// Phương thức: getAll()
// Mục đích: Lấy toàn bộ vector khóa học (để duyệt từ bên ngoài)
// Trả về: Tham chiếu hằng đến vector courses
// 
// GIẢI THÍCH:
// - Trả về const reference để tránh copy và ngăn sửa đổi
// - Cho phép bên ngoài duyệt qua danh sách
// ============================================================================
const vector<Course>& CourseList::getAll() const {
    return courses;
}
