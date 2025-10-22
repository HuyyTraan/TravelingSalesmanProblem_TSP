# 🚀 Discrete Structures Project – Bellman-Ford & Traveling Salesman Problem

**Trường Đại học Bách Khoa – ĐHQG TP.HCM (HCMUT)**  
**Khoa Khoa Học & Kỹ Thuật Máy Tính (CSE)**  
**Môn học:** Cấu trúc rời rạc – Kỳ 232  
**Bài tập lớn (BTL)**  

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
┣ 📜 main.cpp → Chương trình chính: đọc dữ liệu, gọi Bellman-Ford & TSP.
┣ 📜 bellman.h → Khai báo hàm & prototype cho Bellman-Ford.
┣ 📜 bellman.cpp → Cài đặt chi tiết thuật toán Bellman-Ford.
┣ 📜 tsm.h → Khai báo hàm & prototype cho Traveling Salesman.
┣ 📜 tsm.cpp → Cài đặt chi tiết bài toán TSP (branch & bound).
┣ 📜 inMat1.txt → Ma trận kề đầu vào (ví dụ 12x12).
┗ 📜 README.md → Tài liệu mô tả dự án.

