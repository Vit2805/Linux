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
