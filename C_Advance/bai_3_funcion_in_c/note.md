# 1. Function là gì?
- Cách đặt tên function trong công ty:  prefix(tên công ty)-vùng thực hiện source code-tính năng của code.
- Một hàm là một đoạn chương trình độc lập thực hiện một nhiệm vụ cụ thể, được xác định rõ.
- Các hàm thường được sử dụng như các từ viết tắt cho một loạt các hướng dẫn sẽ được thực hiện nhiều lần.
- Các hàm dễ viết và dễ hiểu.
- Việc gỡ lỗi chương trình trở nên dễ dàng hơn vì cấu trúc của chương trình dễ dàng hơn.
- Các chương trình chứa các hàm sẽ dễ bảo trì hơn.

* Việc chia thành nhiều lớp, các hàm có thể sửa đổi dữ liệu sẽ dễ dàng
- Đường stream: có đường read, write (trong hdh linux có thêm đường debug).
- buffer: data
* Trong code C chỉ có truyền dữ liệu hoặc địa chỉ (tham trị và tham chiếu ở trong C++)
# 2. Invoking a function

- Dấu chấm phẩy được sử dụng ở cuối câu lệnh khi một hàm được gọi, nhưng không phải sau định nghĩa hàm.
- Dấu ngoặc đơn là bắt buộc sau tên hàm, bất kể hàm có đối số hay không.
- Chỉ một giá trị có thể được trả về bởi một hàm.
- Chương trình có thể có nhiều hơn một hàm.
- Hàm gọi một hàm khác được gọi là hàm/thủ tục gọi.
- Hàm được gọi là hàm/thủ tục được gọi.

# 3. Function prototype
- Tương tự như định nghĩa hàm nhưng không có nội dung.
- Rất quan trọng vì nó thông báo cho trình biên dịch biết từ nhận dạng có nghĩa gì và cách sử dụng thứ được nhận dạng.
- Khi bạn khai báo một hàm với extern, nó sẽ thông báo với trình biên dịch rằng nó được định nghĩa ở một nơi khác. Tuy nhiên trong C, tất cả các hàm khai báo đều ngầm định là extern.

# 4. Function scope 
- Mỗi source file sẽ trở thành 1 file object kết hợp với nhau thành 1 file execute.

# 5. Passing argument by value (Dễ bị hỏi)
- Sử dụng truyền địa chỉ vào hàm: 
    + hiệu quả về thời gian và không gian lớn hơn: ví dụ hàm có nhiều tham số đầu vào.
    + hàm có thể thay đổi giá trị của đối số, thay đổi phản ánh trong hàm gọi.
    + hàm có nhiều đầu ra.

# 6. Function KeyWord

- *Static* function (một hàm tĩnh) là một hàm có phạm vi sử dụng giới hạn trong file mà nó được khai báo. Điều này có nghĩa là hàm tĩnh không thể được truy cập hoặc sử dụng bởi các hàm hoặc mã trong file khác, ngay cả khi chúng là một phần của cùng một chương trình. 

- *Inline* (hàm nội tuyến): 
    + là một hàm được khai báo với từ khóa inline. Khi sử dụng từ khóa này, bạn đề nghị chương trình chèn toàn bộ mã của hàm vào vị trí mà hàm được gọi, thay vì thực hiện một lời gọi hàm thông thường
    + Điều này có thể giúp giảm thời gian thực thi chương trình, đặc biệt là đối với các hàm nhỏ và được gọi thường xuyên, vì nó loại bỏ chi phí của việc gọi hàm(lưu trữ giá trị trả về, sao chép tham số và chuyền điều khiển).
*Note*: inline function có nhiệm vụ thay thế các đoạn code bên trong bằng hàm, thay vì nhảy đến địa chỉ của hàm và thực hiện. Từ khóa static inline funcion chỉ hoạt động trong phạm vi file object của main.c, tránh xảy ra lỗi multiple definition, tối ưu hiệu suất nhờ inline function (từ khóa này chỉ sử dụng ở trong file.h).

# 7. Function-like Macro 
- Trong C được định nghĩa để hoạt động giống như các hàm. Chúng được khai báo bằng chỉ thị #define với dấu ngoặc đơn đằng sau tên.