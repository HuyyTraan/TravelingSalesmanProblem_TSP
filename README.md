# 🚀 Discrete Structures Project – Bellman-Ford & Traveling Salesman Problem

**Trường Đại học Bách Khoa – ĐHQG TP.HCM (HCMUT)**  
**Khoa Khoa Học & Kỹ Thuật Máy Tính (CSE)**  
**Môn học:** Cấu trúc rời rạc – Kỳ 232  
**Bài tập lớn (BTL)**     
**Trần Vũ Đình Huy** 
---     
        
## 📘 Giới thiệu
 
Dự án này triển khai hai bài toán cổ điển trong lĩnh vực **đồ thị (graph theory)**:   

1. **Thuật toán Bellman-Ford**   
   → Tìm đường đi ngắn nhất từ một đỉnh nguồn đến các đỉnh còn lại trong đồ thị có trọng số (bao gồm trọng số âm).
   
2. **Bài toán Người Du Lịch (Traveling Salesman Problem – TSP)**  
   → Tìm hành trình có tổng chi phí nhỏ nhất đi qua **tất cả các đỉnh một lần duy nhất** và quay lại điểm xuất phát.

Tất cả được cài đặt **thuần C++**, sử dụng **ma trận kề** (`adjacency matrix`) đọc từ file đầu vào.

---

## 📂 Cấu trúc thư mục 
📦 Project/  
├── 📄 main.cpp → Chương trình chính: đọc dữ liệu, gọi Bellman-Ford & TSP.  
├── 📄 bellman.h → Khai báo hàm & prototype cho Bellman-Ford.  
├── 📄 bellman.cpp → Cài đặt chi tiết thuật toán Bellman-Ford.  
├── 📄 tsm.h → Khai báo hàm & prototype cho Traveling Salesman.  
├── 📄 tsm.cpp → Cài đặt chi tiết bài toán TSP (branch & bound).  
├── 📄 inMat1.txt → Ma trận kề đầu vào (ví dụ 12x12).  
└── 📄 README.md → Tài liệu mô tả dự án.  


---

## ⚙️ Cách biên dịch & chạy chương trình

### 🔧 Biên dịch (trên Linux / macOS / Windows có g++)

```bash
g++ main.cpp bellman.cpp tsm.cpp -o project
./project

🧩 Chi tiết cài đặt
🔹 1. Thuật toán Bellman-Ford

File: bellman.cpp

Hàm chính:

void BF(int graph[20][20], int n, char startVertex, int distance[20], int predecessor[20]);
std::string BF_Path(int graph[20][20], int n, char start, char goal);


Ý tưởng:

Khởi tạo khoảng cách (distance[]) và đỉnh trước (predecessor[]).

Lặp |V|−1 lần để thư giãn (relax) các cạnh.

Nếu phát hiện đường đi ngắn hơn → cập nhật lại giá trị.

Sau khi chạy xong, dựng đường đi từ goal ngược về start.

Kết quả:

In ra các bước cập nhật distance và predecessor.

Hiển thị đường đi ngắn nhất từ A → L.

🔹 2. Traveling Salesman Problem (TSP)

File: tsm.cpp

Hàm chính:

std::string Traveling(const int graph[20][20], int n, char startVertex);
int pathlength(const int G[20][20], int n, const std::string &path);


Ý tưởng:

Duyệt toàn bộ hoán vị các đỉnh bằng stack-based DFS + branch & bound.

Mỗi trạng thái gồm:

Đỉnh hiện tại, chi phí hiện tại, danh sách đỉnh đã đi qua, vector visited[].

Dùng giá trị cạnh nhỏ nhất (minEdgeWeight) để ước lượng cận dưới (lower bound).

Cập nhật minimumCost và optimalPath khi tìm được hành trình tốt hơn.

Kết quả:

Hiển thị hành trình tối ưu (ví dụ A C D H L A).

Tính tổng chi phí hành trình (pathlength).

📊 Ví dụ output
Bellman-Ford algorithm:
Step 1:
0 33 40 72 81 ...
-1 0 1 2 3 ...
Step 2:
0 33 40 68 77 ...
...

Shortest path from A to L: A B D H L

Traveling Salesman Problem:
Shortest path: A C D H L A
Total cost: 214

🧠 Kiến thức áp dụng

Cấu trúc dữ liệu: mảng, vector, stack, ma trận kề

Thuật toán đồ thị: Bellman-Ford, TSP (nhánh cận)

Tối ưu hóa: Branch & Bound, lower bound estimation

Kỹ năng C++: nhập/xuất file (fstream), vòng lặp, struct, stack-based search


🏫 Thông tin học phần

Môn: Cấu trúc rời rạc (CO1007)

Trường: Đại học Bách Khoa – ĐHQG TP.HCM

Kỳ: 232

Dự án được chia sẻ với mục đích học tập và tham khảo.
Vui lòng ghi nguồn khi sử dụng hoặc chỉnh sửa lại mã nguồn.

💡 Hướng phát triển thêm

 Thêm chức năng phát hiện chu trình âm trong Bellman-Ford

 Nâng cấp TSP với heuristic như Nearest Neighbor, 2-opt

 Viết giao diện đồ họa (bằng Qt hoặc SDL) để trực quan hóa đường đi

 Thêm đọc/ghi JSON hoặc CSV để nhập/xuất dữ liệu dễ dàng hơn 

