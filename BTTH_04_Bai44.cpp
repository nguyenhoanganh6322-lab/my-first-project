#include <stdio.h>

#define MAX 100

void nhapMang(int a[], int *n)
{
    int i;
    do
    {
        printf("Nhap so phan tu (1-%d): ", MAX);
        scanf("%d", n);
    } while (*n < 1 || *n > MAX);
    for (i = 0; i < *n; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

void xuatMang(const int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int tongLe(const int a[], int n)
{
    int i, tong = 0;
    for (i = 0; i < n; i++)
        if (a[i] % 2 != 0)
            tong += a[i];
    return tong;
}

double trungBinhCong(const int a[], int n)
{
    int i;
    double tong = 0;
    for (i = 0; i < n; i++)
        tong += a[i];
    return tong / n;
}

int giaTriNhoNhat(const int a[], int n)
{
    int i, min = a[0];
    for (i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

int viTriLonNhat(const int a[], int n)
{
    int i, vt = 0;
    for (i = 1; i < n; i++)
        if (a[i] > a[vt])
            vt = i;
    return vt + 1;
}

int toanChan(const int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] % 2 != 0)
            return 0;
    return 1;
}

void lietKeDuong(const int a[], int n)
{
    int i, co = 0;
    for (i = 0; i < n; i++)
        if (a[i] > 0)
        {
            printf("%d ", a[i]);
            co = 1;
        }
    if (!co)
        printf("khong co so duong trong mang");
    printf("\n");
}

void lietKeLonHonTBC(const int a[], int n)
{
    int i, co = 0;
    double tbc = trungBinhCong(a, n);
    for (i = 0; i < n; i++)
        if (a[i] > tbc)
        {
            printf("%d ", a[i]);
            co = 1;
        }
    if (!co)
        printf("khong co phan tu nao");
    printf("\n");
}

void lietKeChanLe(const int a[], int n)
{
    int i;
    printf("Cac so chan: ");
    for (i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            printf("%d ", a[i]);
    printf("\n");
    printf("Cac so le: ");
    for (i = 0; i < n; i++)
        if (a[i] % 2 != 0)
            printf("%d ", a[i]);
    printf("\n");
}

int laNguyenTo(int x)
{
    int i;
    if (x < 2)
        return 0;
    for (i = 2; i <= x / i; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

int laChinhPhuong(int x)
{
    long long i;
    if (x < 0)
        return 0;
    for (i = 0; i * i <= x; i++)
        if (i * i == x)
            return 1;
    return 0;
}

void lietKeNguyenTo(const int a[], int n)
{
    int i, co = 0;
    for (i = 0; i < n; i++)
        if (laNguyenTo(a[i]))
        {
            printf("%d ", a[i]);
            co = 1;
        }
    if (!co)
        printf("khong co so nguyen to trong mang");
    printf("\n");
}

void lietKeChinhPhuong(const int a[], int n)
{
    int i, co = 0;
    for (i = 0; i < n; i++)
        if (laChinhPhuong(a[i]))
        {
            printf("%d ", a[i]);
            co = 1;
        }
    if (!co)
        printf("khong co so chinh phuong trong mang");
    printf("\n");
}

int main()
{
    int a[MAX];
    int n;
    nhapMang(a, &n);
    printf("\nMang vua nhap: ");
    xuatMang(a, n);
    printf("Tong cac so le: %d\n", tongLe(a, n));
    printf("Trung binh cong: %.2f\n", trungBinhCong(a, n));
    printf("Gia tri nho nhat: %d\n", giaTriNhoNhat(a, n));
    printf("Vi tri phan tu lon nhat: %d\n", viTriLonNhat(a, n));
    printf("Toan bo la so chan (1: dung, 0: sai): %d\n", toanChan(a, n));
    printf("Cac so duong: ");
    lietKeDuong(a, n);
    printf("Cac phan tu lon hon trung binh cong: ");
    lietKeLonHonTBC(a, n);
    lietKeChanLe(a, n);
    printf("Cac so nguyen to: ");
    lietKeNguyenTo(a, n);
    printf("Cac so chinh phuong: ");
    lietKeChinhPhuong(a, n);
    printf("\nNhan Enter de thoat...");
    getchar();
    getchar();
    return 0;
}
