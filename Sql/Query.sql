
-- comment here

CREATE DATABASE IT

-- Thực thi code nguyên file nhấn F5 hoặc Execute

-- Thực thi 1 đoạn code nào thì bôi đen đoạn code đó rồi nhấn F5 hoặc Execute

-- Tạo: CREATE <thứ cần tạo> <tên>

-- Ex: CREATE DATABASE IT

-- Sữ dụng database : USE <tên database>

GO

USE IT 

GO

-- Lệnh ngắn code: GO

-- Thực thi trên xuống . Làm trên GO trước dưới GO sau

CREATE TABLE HocSinh(
	Id NVARCHAR(11),
	Name NVARCHAR(50),
	BDay Date
)
GO
-- Xóa: DROP <thuộc tính xóa> <tên thuộc tính đó>

-- Ex: DROP DATABASE DB

 DROP TABLE HocSinh

 GO

 -- Thêm 1 dòng dữ liệu


INSERT dbo.HocSinh (Id, Name, BDay)
VALUES ( N'3118410332' ,-- Chèn ID 
		 N'Trần Thanh Phong', -- Chèn họ tên. Unicode nên có N phía trước
		 '20000602'
		 )
GO

INSERT dbo.HocSinh -- Một cách chèn khác
VALUES ( N'123456789',
		 N'Nguyễn Hoàng Như Ý',
		 '20021104'
		
)
GO

DELETE dbo.HocSinh WHERE Id = N'123456789' -- Delete những gì thỏa điểu kiện where

GO

SELECT TOP 2 [Id], [Name], [BDay]

FROM [IT].[dbo].[HocSinh]

CREATE TABLE KHOA(
	MAKHOA NVARCHAR(11) PRIMARY KEY NOT NULL,
	TENKHOA NVARCHAR(50) NOT NULL,
	NAMTHANHLAP DATE
)
-- Tạo khóa chính
ALTER TABLE dbo.KHOA ADD CONSTRAINT
PK_KHOA PRIMARY KEY(MAKHOA)
--
CREATE TABLE SVIEN(
	MASV NVARCHAR(11) PRIMARY KEY NOT NULL,
	TEN NVARCHAR(50) NOT NULL,
	NAM DATE,
	MAKH NVARCHAR(11)
)
-- Tạo khóa ngoại
ALTER TABLE dbo.SVIEN ADD CONSTRAINT
FK_SV_KHOA FOREIGN KEY (MAKH) REFERENCES KHOA(MAKHOA) -- FOREIGN KEY (cột ở sv) REFERENCES KHOA(khóa ở khoa)
-- Okkk 
CREATE TABLE MHOC(
	MAMH NVARCHAR(11) PRIMARY KEY NOT NULL,
	TENMH NVARCHAR(50) NOT NULL,
	TINCHI INT NOT NULL,
	MAKH NVARCHAR(11) NOT NULL
)
ALTER TABLE dbo.MHOC ADD CONSTRAINT
FK_MHOC_KHOA FOREIGN KEY (MAKH) REFERENCES KHOA(MAKHOA)