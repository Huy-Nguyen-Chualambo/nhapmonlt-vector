#  Quản Lý Thông Tin Khóa Học (Phiên bản Vector)

> **Bài tập lớn môn Nhập môn Lập trình**  
> Đề tài 5: Quản lý thông tin khóa học  
> **Phiên bản: Vector (Mảng động)**

---

##  Mô tả

Chương trình quản lý thông tin khóa học sử dụng **std::vector (Mảng động)** và **Lập trình hướng đối tượng (OOP)** trong C++.

---

##  Chức năng

| STT | Chức năng | Mô tả |
|:---:|-----------|-------|
| 1 | Thêm khóa học | Thêm mới với kiểm tra trùng mã, tín chỉ > 0, SV >= 0 |
| 2 | Hiển thị tất cả | In danh sách khóa học dạng bảng |
| 3 | Tìm kiếm | Tìm theo mã khóa học |
| 4 | Thống kê Max | Khóa học có nhiều SV đăng ký nhất |
| 5 | Thống kê Min | Khóa học có ít SV đăng ký nhất |
| 0 | Thoát | Thoát chương trình |

---

##  Cấu trúc dự án

```
nhapmonlt-vector/
├── Course.h              # Header - Lớp Khóa học
├── Course.cpp            # Implementation - Lớp Khóa học
├── CourseList.h          # Header - Lớp quản lý danh sách (dùng vector)
├── CourseList.cpp        # Implementation - Lớp quản lý danh sách
├── Utils.h               # Header - Các hàm tiện ích giao diện
├── Utils.cpp             # Implementation - Các hàm tiện ích
├── main.cpp              # File chính - Hàm main()
├── Makefile              # File tự động hóa biên dịch
├── .gitignore            # Danh sách file Git bỏ qua
└── README.md             # File hướng dẫn (file này)
```

---

##  Cài đặt và Chạy

### Yêu cầu
- Trình biên dịch C++ (g++ hoặc tương đương)
- Hỗ trợ C++11 trở lên

### Tải mã nguồn

**Cách 1: Clone từ Git**
```bash
git clone https://github.com/HoangTuBangGia/nhapmonlt-vector.git
cd nhapmonlt-vector
```

**Cách 2: Tải file ZIP**
1. Nhấn nút **Code** → **Download ZIP** trên GitHub
2. Giải nén file `nhapmonlt-vector-main.zip`
3. Mở terminal và di chuyển vào thư mục:
```bash
cd nhapmonlt-vector-main
```

### Biên dịch và chạy

```bash
# Biên dịch
make

# Biên dịch và chạy chương trình
make run

# Hoặc chỉ chạy (không biên dịch lại)
make exec
```

### Các lệnh Make khác

| Lệnh | Mô tả |
|------|-------|
| `make` | Biên dịch chương trình |
| `make run` | Biên dịch (nếu cần) + chạy |
| `make exec` | Chỉ chạy file đã biên dịch |
| `make clean` | Xóa file .o, giữ file thực thi |
| `make cleanall` | Xóa tất cả file biên dịch |
| `make rebuild` | Biên dịch lại từ đầu |

---

##  Cấu trúc dữ liệu

### std::vector (Mảng động)

```
┌─────────┬─────────┬─────────┬─────────┬─────────┐
│ [0]     │ [1]     │ [2]     │ [3]     │ [4]     │  ...
│ Course  │ Course  │ Course  │ Course  │ Course  │
└─────────┴─────────┴─────────┴─────────┴─────────┘
     ↑
  Truy cập qua chỉ số (index)
```

**Đặc điểm của vector:**
- Các phần tử nằm liền kề trong bộ nhớ
- Truy cập ngẫu nhiên O(1) qua chỉ số
- Tự động mở rộng khi thêm phần tử
- Không cần quản lý con trỏ thủ công

### Lớp Course (Khóa học)

| Thuộc tính | Kiểu | Mô tả |
|------------|------|-------|
| `courseId` | string | Mã khóa học (duy nhất) |
| `courseName` | string | Tên khóa học |
| `credits` | int | Số tín chỉ (> 0) |
| `studentCount` | int | Số SV đăng ký (>= 0) |

---

##  So sánh Vector và Doubly Linked List

## So sánh các cấu trúc dữ liệu (Linked List vs. std::vector)

| Tiêu chí so sánh | Danh sách liên kết đôi (Linked List) | Mảng động (std::vector) |
| :--- | :--- | :--- |
| **Quản lý bộ nhớ** | Linh hoạt, cấp phát theo Node; tốn thêm bộ nhớ cho con trỏ `prev`, `next`. | Lưu trữ liên tiếp; tiết kiệm con trỏ nhưng có thể cấp phát dư (`capacity`). |
| **Tốc độ truy xuất** | **Chậm $O(n)$**: Phải duyệt tuần tự từ đầu danh sách. | **Nhanh $O(1)$**: Truy xuất trực tiếp qua chỉ số (index). |
| **Tốc độ Thêm/Xóa**| **Nhanh $O(1)$**: Chỉ cần thay đổi liên kết con trỏ nếu đã biết vị trí. | **Chậm $O(n)$**: Phải dịch chuyển các phần tử phía sau khi thao tác ở giữa. |
| **Độ phức tạp Code** | **Cao**: Phải quản lý con trỏ và bộ nhớ thủ công (`new`/`delete`). | **Thấp**: Sử dụng thư viện STL tối ưu, code ngắn gọn và an toàn hơn. |

(*) O(1) trung bình, có thể O(n) khi phải mở rộng mảng

(**) O(n) để tìm vị trí + O(1) để chèn/xóa. Nếu đã có con trỏ đến node thì chỉ O(1)

---

