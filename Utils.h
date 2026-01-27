/*
 * ============================================================================
 * File: Utils.h
 * Mô tả: Header file cho các hàm tiện ích (Utility Functions)
 * Phiên bản: Vector (Mảng động)
 * ============================================================================
 */

#ifndef UTILS_H
#define UTILS_H

#include "Course.h"
#include <string>
using namespace std;

// Xóa màn hình console
void clearScreen();

// Dừng màn hình để người dùng đọc kết quả
void pauseScreen();

// In tiêu đề cho mỗi chức năng với định dạng đẹp
void printHeader(string title);

// In tiêu đề bảng với định dạng cột đẹp
void printTableHeader();

// In một dòng dữ liệu khóa học trong bảng
void printTableRow(Course course);

// In đường kẻ cuối bảng
void printTableFooter();

// Hiển thị menu chính với giao diện đẹp
void printMainMenu();

// Hiển thị thông báo thoát chương trình
void showExitMessage();

#endif // UTILS_H
