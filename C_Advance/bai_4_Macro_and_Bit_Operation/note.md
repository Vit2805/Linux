# 1. Preprocessor overview
- Quá trình tiền xử lý bao gồm các chỉ thị tiền xử lý cần được thực thi và các macro cần được mở rộng:
    + Bao gồm các thư viện 
    + Đọc các macro 
    + Biên dịch có điều kiện
    + Chỉ thị chẩn đoán.
- Chỉ thị tiền xử lý là các dòng bắt đầu bằng ký hiệu '#'.

# 2. Macro 
- Macro là một đoạn mã đã được đặt tên. Bất cứ khi nào tên được sử dụng, nó sẽ được thay thế bằng nội dung của macro.
- Macro được định nghĩa bằng cách sử dụng tiền xử lý #define trong ngôn ngữ C.
- Macro được sử dụng khi tạo hằng số biểu diễn số, chuỗi hoặc biểu thức.
- Phân loại macro: 
    + Predefined macro
    + User-defined macro
# 3. Function like macro 
- tên đặt được bằng dấu gạch dưới. Danh sách parameters không có cách trắng.
- mỗi tham số phải được bảo vệ bằng dấu gạch đơn

# 4. Conditional compilation

- #if: Chỉ thị này kiểm tra xem một điều kiện nào đó có đúng không. Nếu điều kiện
được đánh giá là đúng, trình biên dịch sẽ bao gồm mã giữa #if và chỉ thị
- #endif, #else hoặc #elif tiếp theo.
- #ifdef: Chỉ thị này kiểm tra xem macro có được định nghĩa hay không. Nếu macro được định nghĩa,
mã theo sau #ifdef cho đến #endif, #else hoặc #elif sẽ được biên dịch.
- #ifndef: Ngược lại với #ifdef. Chỉ thị này kiểm tra xem macro có được định nghĩa hay không. Nếu
macro không được định nghĩa, mã theo sau #ifndef sẽ được biên dịch.
- #else: Được sử dụng với #if, #ifdef hoặc #ifndef. Nếu điều kiện trước đó là
false, trình biên dịch sẽ bao gồm mã theo sau #else.
- #elif: Viết tắt của “else if”. Cho phép sử dụng nhiều biểu thức điều kiện. Nếu
- #if, #ifdef hoặc #ifndef trước đó là sai và điều kiện trong #elif là
true, mã theo sau #elif sẽ được biên dịch.
- #endif: Đánh dấu kết thúc khối biên dịch có điều kiện bắt đầu bằng #if,
- #ifdef, #ifndef, #else hoặc #elif.
- #define: Được sử dụng để định nghĩa các macro, có thể được sử dụng trong biên dịch có điều kiện.
- #undef: Được sử dụng để hủy định nghĩa các macro.

# 5. Bit operattions 

- Thiết lập một bit có nghĩa là đảm bảo nó là 1.
    number |= (1 << vị trí)
- Xóa một bit có nghĩa là đảm bảo nó là 0.
    number &= ~(1 << vị trí)
- Đọc một bit sẽ kiểm tra xem nó là 0 hay 1.
    bit = (number >> vị trí) & 1
- Sửa đổi (Chuyển đổi) một Bit
- Chuyển đổi một bit sẽ lật ngược nó: 1 thành 0 và 0 thành 1.
    number ^= (1 << vị trí)
- Sửa đổi (Đặt một Bit thành Giá trị Cụ thể)
Nếu bạn muốn đặt một bit thành một giá trị cụ thể (1 hoặc 0):
    number = (number & ~(1 << vị trí)) | (value << vị trí)