CREATE TABLE medicoes_estufa (
    id INT AUTO_INCREMENT PRIMARY KEY,
    temperatura DECIMAL(5,2) NOT NULL,
    umidade DECIMAL(5,2) NOT NULL,
    luminosidade INT NOT NULL,
    data_hora TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);