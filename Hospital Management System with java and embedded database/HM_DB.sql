CREATE TABLE users (
  id int  AUTO_INCREMENT,
  name varchar(255) ,
  username varchar(255) ,
  password varchar(255) ,
  utype varchar(255) ,
  PRIMARY KEY (id)
);


CREATE TABLE doctor (
  doctorno varchar(255) ,
  name varchar(255) ,
  special varchar(255) ,
  qualification varchar(255) ,
  reservation_fee int ,
  phone int ,
  room int ,
  log_id int ,
  PRIMARY KEY (doctorno),
FOREIGN KEY (log_id) REFERENCES users(id)
);

CREATE TABLE sales (
  id int  AUTO_INCREMENT,
  date date ,
  subtotal int ,
  pay int ,
  balance int ,
  PRIMARY KEY (id)
);

CREATE TABLE item (
  itemid varchar(255) ,
  itemname varchar(255) ,
  description varchar(255) ,
  sellprice int ,
  buyprice int ,
  qty int ,
  PRIMARY KEY (itemid)
) ;

CREATE TABLE patient (
  patientno varchar(255) ,
  name varchar(255) ,
  phone int ,
  address varchar(255) ,
  PRIMARY KEY (patientno)
);

CREATE TABLE reservation (
  reservationno varchar(255) ,
  doctorname varchar(255) ,
  patientname varchar(255) ,
  roomno int ,
  date date ,
  PRIMARY KEY (reservationno)
);

CREATE TABLE prescription (
  pid varchar(255) ,
  reservationid varchar(255) ,
  doctorname varchar(255) ,
  detype varchar(255) ,
  description varchar(255) ,
  PRIMARY KEY (pid),
FOREIGN KEY (reservationid) REFERENCES reservation(reservationno)
);

CREATE TABLE sale_product (
  id int  AUTO_INCREMENT,
  sales_id int ,
  prod_id varchar(255) ,
  sellprice int ,
  qty int ,
  total int ,
  PRIMARY KEY (id),
FOREIGN KEY (sales_id) REFERENCES sales(id)
);
