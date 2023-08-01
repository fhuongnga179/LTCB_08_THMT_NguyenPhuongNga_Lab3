// 0850080033_NguyenPhuongNga_08THMT

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// ==========================================================
// 1
void timmin(int a, int b)
{
    int sonho = min(a, b);
    cout << "số nhỏ nhất là: " << sonho;
}

// 2
void uocchunglonnhat(int a, int b)
{
    if (a == 0 || b == 0)
    {
        cout << a + b;
    }
    while (a != b)
    {
        if (a > b)
        {
            int uocchunglonnhat = a - b;
            cout << "ước chung lớn nhất là: " << uocchunglonnhat << endl;
            break;
        }
        else
        {
            int uocchunglonnhat = b - a;
            cout << "ước chung lớn nhất là: " << uocchunglonnhat << endl;
            break;
        }
    }
}
void boichungnhonhat(int a, int b)
{
    int maxB = a * b;
    int BCNN;
    for (int i = max(a, b); i <= maxB; i++)
    {
        if (i % a == 0 && i % b == 0)
        {
            BCNN = i;
            break;
        }
    }
    cout << "BCNN là: của " << a << " và " << b << " là: " << BCNN;
}

// 3
void tinhgiaithua(int n)
{
    int giaithua = 1;
    for (int i = 1; i <= n; i++)
    {
        giaithua = giaithua * i;
    }
    cout << "Tổng của giai thừa" << n << "! là: " << giaithua;
}

// 4
void luyThua(double x, int n, double *ketQua)
{
    *ketQua = 1.0;
    bool laSoMuAm = n < 0;
    if (laSoMuAm)
    {
        n = -n; // Chuyển số mũ thành dương
    }

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            *ketQua *= x;
        }
        x *= x;
        n /= 2;
    }

    if (laSoMuAm)
    {
        *ketQua = 1.0 / *ketQua;
    }
}

// 5
double tinhChuVi(double chieuDai, double chieuRong)
{
    return 2 * (chieuDai + chieuRong);
}

double tinhDienTich(double chieuDai, double chieuRong)
{
    return chieuDai * chieuRong;
}

void veHinhChuNhat(int chieuDai, int chieuRong)
{
    for (int i = 0; i < chieuRong; i++)
    {
        for (int j = 0; j < chieuDai; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// 7
bool laSoHoanThien(int num)
{
    if (num <= 0)
    {
        return false;
    }
    int sum = 0;
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    return sum == num;
}
void inCacSoHoanThienNhoHon(int n)
{
    cout << "Các số hoàn thiện nhỏ hơn " << n << " là: ";
    for (int i = 1; i < n; i++)
    {
        if (laSoHoanThien(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

// 9
int daoso(int n)
{
    int daonguoc = 0;
    while (n > 0)
    {
        int digit = n % 10;               // Lấy số cuôis
        daonguoc = daonguoc * 10 + digit; // Đảo ngược, + số mớio
        n /= 10;
    }
    return daonguoc;
}

// 10
bool laNamNhuan(int nam)
{
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int soNgayTrongThang(int thang, int nam)
{
    int ngayTrongThang[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (thang == 2 && laNamNhuan(nam))
    {
        return 29;
    }
    return ngayTrongThang[thang];
}

bool ngayHopLe(int ngay, int thang, int nam)
{
    if (thang < 1 || thang > 12)
    {
        return false;
    }
    if (ngay < 1 || ngay > soNgayTrongThang(thang, nam))
    {
        return false;
    }
    return true;
}

void timNgayHS(int &ngay, int &thang, int &nam)
{
    ngay++;
    if (ngay > soNgayTrongThang(thang, nam))
    {
        ngay = 1;
        thang++;
        if (thang > 12)
        {
            thang = 1;
            nam++;
        }
    }
}

void timNgayHT(int &ngay, int &thang, int &nam)
{
    ngay--;
    if (ngay == 0)
    {
        thang--;
        if (thang == 0)
        {
            thang = 12;
            nam--;
        }
        ngay = soNgayTrongThang(thang, nam);
    }
}

// 11
void inCacGiaiTheThao(int nam)
{
    cout << "Các giải thể thao được tổ chức trong năm " << nam << " là: ";

    bool hasGiaiTheThao = false;

    if (nam >= 1988 && nam % 4 == 0)
    {
        cout << "Olympic, Euro ";
        hasGiaiTheThao = true;
    }

    if (nam >= 1990 && nam % 4 == 2)
    {
        cout << "World Cup ";
        hasGiaiTheThao = true;
    }

    if (nam % 2 == 1 && nam >= 1995)
    {
        cout << "SEA Games ";
        hasGiaiTheThao = true;
    }

    if (nam % 2 == 0 && nam >= 1996)
    {
        cout << "Tiger Cup ";
        hasGiaiTheThao = true;
    }

    if (!hasGiaiTheThao)
    {
        cout << "Không có giải thế thao lớn nào.";
    }

    cout << endl;
}

// ===========================================================
int main()
{
    cout << "Nhập câu hỏi của bài LAB3 - Bài tập cơ bản?" << endl;

    cout << "1. Tìm số nhỏ nhất" << endl;
    cout << "2. Viết hàm tính UCLN và BCNN của 2 số nguyên dương a, b" << endl;
    cout << "3. Tính giai thừa " << endl;
    cout << "4. Hàm tính X^n không dùng đệ quy " << endl;
    cout << "6. Vẽ hình tam giác " << endl;
    cout << "7. Số hoàn thiện " << endl;
    // cout << "8. Tính toán tiền " << endl;
    cout << "9. Đảo số " << endl;
    cout << "10. BT ứng dụng: Tính ngày " << endl;
    cout << "11. BT ứng dụng: Bóng đá theo năm " << endl;

    cout << "Số nhập là: ";

    int n;
    cin >> n;
    switch (n)
    {
        // =========================================
    case 1:
    {
        int a, b;
        cout << "nhập vào 2 số a và b: ";
        cin >> a >> b;
        timmin(a, b);
        break;
    }

    case 2:
    {
        int a, b;
        cout << "nhập vào 2 số a và b: ";
        cin >> a >> b;
        uocchunglonnhat(a, b);
        boichungnhonhat(a, b);
        break;
    }

    case 3:
    {
        int n;
        cout << "Nhập số giai thừa: ";
        cin >> n;
        tinhgiaithua(n);
        break;
    }
    case 4:
    {
        double x;
        int n;
        double ketQua;
        cout << "Nhập giá trị X: ";
        cin >> x;
        cout << "Nhập số mũ N: ";
        cin >> n;
        luyThua(x, n, &ketQua);
        cout << x << " ^ " << n << " = " << ketQua << endl;
        break;
    }
    case 6:
    {
        double chieuDai, chieuRong;
        cout << "Chiều dài: ";
        cin >> chieuDai;
        cout << "Chiều rộng: ";
        cin >> chieuRong;

        double chuVi = tinhChuVi(chieuDai, chieuRong);
        double dienTich = tinhDienTich(chieuDai, chieuRong);

        cout << "Chu vi: " << chuVi << endl;
        cout << "Diện tích: " << dienTich << endl;

        veHinhChuNhat(chieuDai, chieuRong);
        break;
    }
    case 7:
    {
        int num;
        cout << "Nhập một số nguyên dương: ";
        cin >> num;
        if (laSoHoanThien(num))
        {
            cout << num << " là một số hoàn thiện." << endl;
        }
        else
        {
            cout << num << "không phải là số hoàn thiện." << endl;
        }
        inCacSoHoanThienNhoHon(num);
        break;
    }
    case 8:
    {
        break;
    }
    case 9:
    {
        int n;
        cout << "Nhập một số nguyên dương: ";
        cin >> n;
        int daonguoc = daoso(n);
        cout << "Số đảo ngược là" << daonguoc << endl;
        break;
    }

    case 10:
    {
        int ngay, thang, nam;
        cout << "Nhập ngày: ";
        cin >> ngay;
        cout << "Nhập tháng: ";
        cin >> thang;
        cout << "Nhập năm: ";
        cin >> nam;

        if (ngayHopLe(ngay, thang, nam))
        {
            cout << "Ngày tháng năm hợp lệ." << endl;
            cout << "Tháng " << thang << " có " << soNgayTrongThang(thang, nam) << " ngày." << endl;

            int ngayHS = ngay, thangHS = thang, namHS = nam;
            timNgayHS(ngayHS, thangHS, namHS);
            cout << "Ngày hôm sau là: " << ngayHS << "/" << thangHS << "/" << namHS << endl;

            int ngayHT = ngay, thangHT = thang, namHT = nam;
            timNgayHT(ngayHT, thangHT, namHT);
            cout << "Ngày hôm trước là: " << ngayHT << "/" << thangHT << "/" << namHT << endl;
        }
        else
        {
            cout << "Ngày tháng năm không hợp lệ." << endl;
        }
        break;
    }

    case 11:
    {
        int nam;
        cout << "Nhập năm dương (Từ 1975): ";
        cin >> nam;

        if (nam < 1975)
        {
            cout << "Năm không hợp lệ" << endl;
        }
        else
        {
            inCacGiaiTheThao(nam);
        }

        break;
    }
    default:
    {
        cout << "Không có bài tập";
        break;
    }
    }
}
