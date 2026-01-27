/*
 * ============================================================================
 * File: CourseList.h
 * Mô tả: Header file định nghĩa lớp CourseList sử dụng std::vector
 * Phiên bản: Vector (Mảng động)
 * ============================================================================
 */

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"
#include <vector>
#include <string>
using namespace std;

/*
 * Lớp CourseList quản lý danh sách các khóa học.
 * Sử dụng std::vector (mảng động) để lưu trữ.
 * 
 * ƯU ĐIỂM CỦA VECTOR SO VỚI DANH SÁCH LIÊN KẾT:
 * 1. Truy cập ngẫu nhiên O(1) - có thể truy cập phần tử bất kỳ qua chỉ số
 * 2. Cache-friendly - các phần tử nằm liền kề trong bộ nhớ
 * 3. Không cần quản lý con trỏ thủ công
 * 4. Tự động mở rộng kích thước khi cần
 * 
 * NHƯỢC ĐIỂM:
 * 1. Chèn/xóa ở giữa mảng tốn O(n)
 * 2. Có thể phải cấp phát lại bộ nhớ khi mở rộng
 */
class CourseList {
private:
    vector<Course> courses;  // Vector chứa danh sách khóa học

public:
    // ========================================================================
    // Constructor - Khởi tạo danh sách rỗng
    // ========================================================================
    CourseList();

    // ========================================================================
    // Destructor - Vector tự động giải phóng bộ nhớ
    // ========================================================================
    ~CourseList();

    // ========================================================================
    // Phương thức: isEmpty()
    // Mục đích: Kiểm tra danh sách có rỗng không
    // ========================================================================
    bool isEmpty() const;

    // ========================================================================
    // Phương thức: getSize()
    // Mục đích: Lấy số lượng khóa học trong danh sách
    // ========================================================================
    int getSize() const;

    // ========================================================================
    // Phương thức: isIdExist(string id)
    // Mục đích: Kiểm tra mã khóa học đã tồn tại trong danh sách chưa
    // ========================================================================
    bool isIdExist(string id) const;

    // ========================================================================
    // Phương thức: addCourse(Course course)
    // Mục đích: Thêm một khóa học mới vào CUỐI danh sách
    // ========================================================================
    void addCourse(Course course);

    // ========================================================================
    // Phương thức: findById(string id)
    // Mục đích: Tìm kiếm khóa học theo mã
    // Trả về: Chỉ số của khóa học trong vector, -1 nếu không tìm thấy
    // ========================================================================
    int findById(string id) const;

    // ========================================================================
    // Phương thức: getCourse(int index)
    // Mục đích: Lấy khóa học tại vị trí index
    // ========================================================================
    Course getCourse(int index) const;

    // ========================================================================
    // Phương thức: getMaxStudentCount()
    // Mục đích: Tìm số lượng sinh viên đăng ký nhiều nhất
    // ========================================================================
    int getMaxStudentCount() const;

    // ========================================================================
    // Phương thức: getMinStudentCount()
    // Mục đích: Tìm số lượng sinh viên đăng ký ít nhất
    // ========================================================================
    int getMinStudentCount() const;

    // ========================================================================
    // Phương thức: getAll()
    // Mục đích: Lấy toàn bộ vector khóa học (để duyệt từ bên ngoài)
    // ========================================================================
    const vector<Course>& getAll() const;
};

#endif // COURSELIST_H
