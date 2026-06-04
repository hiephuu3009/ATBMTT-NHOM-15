import hashlib
# Ham tim UCLN
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Kiem tra so nguyen to
def la_so_nguyen_to(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

# Euclid mo rong
def mod_inverse(e, phi):
    m0 = phi
    y = 0
    x = 1
    while e > 1:
        q = e // phi
        t = phi
        phi = e % phi
        e = t
        t = y
        y = x - q * y
        x = t
    if x < 0:
        x += m0
    return x

e = d = n = 0

#Tao khoa
def tao_khoa():
    global e, d, n
    p = int(input("Nhap so nguyen to p: "))
    q = int(input("Nhap so nguyen to q: "))

    if not la_so_nguyen_to(p) or not la_so_nguyen_to(q):
        print("p va q phai la so nguyen to!")
        return

    if p == q:
        print("p va q phai khac nhau!")
        return

    n = p * q
    phi = (p - 1) * (q - 1)
    e = 3
    while gcd(e, phi) != 1:
        e += 2
    d = mod_inverse(e, phi)
    print("\n===== KHOA RSA =====")
    print("n =", n)
    print("phi(n) =", phi)
    print("e =", e)
    print("d =", d)

    print("\nPublic Key =", (e, n))
    print("Private Key =", (d, n))

#Ky so
def ky_so():
    global d, n
    if n == 0:
        print("Hay tao khoa truoc!")
        return

    message = input("Nhap thong diep can ky: ")

    hash_value = hashlib.sha256(message.encode()).hexdigest()

    m = int(hash_value, 16) % n

    S = pow(m, d, n)

    print("\nGia tri bam SHA-256:")
    print(hash_value)

    print("\nChu ky so:")
    print(S)

#Xac minh
def xac_minh():
    global e, n

    if n == 0:
        print("Hay tao khoa truoc!")
        return

    message = input("Nhap lai thong diep: ")
    S = int(input("Nhap chu ky: "))

    hash_value = hashlib.sha256(message.encode()).hexdigest()
    m1 = int(hash_value, 16) % n

    m2 = pow(S, e, n)

    print("\nGia tri bam tu thong diep:", m1)
    print("Gia tri giai ma chu ky:", m2)

    if m1 == m2:
        print("\n>>> CHU KY HOP LE")
    else:
        print("\n>>> CHU KY KHONG HOP LE")

#Menu
def main():
    while True:
        print("\n========== MENU RSA ==========")
        print("1. Tao khoa RSA")
        print("2. Ky so van ban")
        print("3. Xac minh chu ky")
        print("4. Thoat")

        chon = input("\nNhap lua chon: ")
        if chon == "1":
            tao_khoa()

        elif chon == "2":
            ky_so()

        elif chon == "3":
            xac_minh()

        elif chon == "4":
            print("Ket thuc chuong trinh!")
            break

        else:
            print("Lua chon khong hop le!")

if __name__ == "__main__":
    main()