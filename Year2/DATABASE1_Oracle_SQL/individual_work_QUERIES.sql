/*  Kingsley Chimezie - C14468272
    Case Study Part 2 - Individual work
    QUERIES
    09/05/16
*/


/* (1) --------------------------------------------------------------------- 
        Granting access to required tables using group schema
*/
  ALTER SESSION SET CURRENT_SCHEMA = DT211C2A5;
  GRANT   INSERT, UPDATE, DELETE    ON     supplier      TO    kchimezie;
  GRANT   INSERT, UPDATE, DELETE    ON     phone_specs   TO    kchimezie;
  GRANT   INSERT, UPDATE, DELETE    ON     stores        TO    kchimezie;
  

/* (2) --------------------------------------------------------------------- 
        Populating Tables
*/
   -- TABLE 1 (SUPPLIER) _____________________________________________
    INSERT INTO DT211C2A5.supplier VALUES ('Doro','Spain');
    INSERT INTO DT211C2A5.supplier VALUES ('Motorola','USA');
    INSERT INTO DT211C2A5.supplier VALUES ('Alcatel','Spain');
    INSERT INTO DT211C2A5.supplier VALUES ('Huawei','China');
    
    DELETE FROM DT211C2A5.supplier WHERE                                    -- clear INSERTS using DELETE
    supplier_name='Doro' OR
    supplier_name='Motorola' OR
    supplier_name='Alcatel' OR
    supplier_name='Huawei';
  
    SELECT * FROM DT211C2A5.supplier;                                       -- view SUPPLIER table


  -- TABLE 2 (PHONE_SPECS) _____________________________________________
    INSERT INTO DT211C2A5.phone_specs VALUES
    (746864646461992,'Sony','Xperia Z5 Premium','20.7mp','','3600',759);
    INSERT INTO DT211C2A5.phone_specs VALUES
    (746864646461998,'Huawei','G7','18mp','','3200',450);
    
    DELETE FROM DT211C2A5.phone_specs                                       -- clear INSERTS using DELETE
      WHERE serial_no='746864646461992' OR 
            serial_no='746864646461998';
    
    SELECT * FROM DT211C2A5.phone_specs;                                    -- view PHONE_SPECS table


   -- TABLE 3 (STORES) _____________________________________________
    INSERT INTO DT211C2A5.stores VALUES 
    (2048,'Blanchardstown',35316754444);
    
    DELETE FROM DT211C2A5.stores WHERE store_id='2048';                     -- clear INSERT using DELETE
    
    SELECT * FROM DT211C2A5.stores;                                         -- view SUPPLIER table


/* (3) --------------------------------------------------------------------- 
        TRANSATION (see SQL file 'C14468272.transaction')
*/
  


/* (4) --------------------------------------------------------------------- */

-- (a) - PROJECTION

  /* Select the store address and phone number for Blackrock store */
  SELECT store_address, store_number FROM DT211C2A5.stores
    WHERE store_address = 'Blackrock';
  ----------------------------------------------
  SELECT * FROM STORES;
  ----------------------------------------------
  
  

-- (b) - SELECTION (Restriction)

  /* Selct the phone brand, phone type and price of phones 
  between 300 - 800 in Price from phone specs */
  SELECT phone_brand, phone_type, price
    FROM DT211C2A5.phone_specs 
    WHERE price BETWEEN 300 AND 800;
  ----------------------------------------------
  SELECT * FROM PHONE_SPECS;
  ----------------------------------------------



-- (c) - SORTING

  /* Select the phone type and price of phones less than 800
  from phone specs and sort them in accending order */
  SELECT phone_type, price FROM DT211C2A5.phone_specs
      WHERE price < 800
        ORDER BY price ASC;
  ----------------------------------------------
  SELECT * FROM PHONE_SPECS;
  ----------------------------------------------
  


-- (d) - NON-AGGREGATE FUNCTION IN THE SELECT LIST

  /*Select store addresses with less with a store id number less than 5*/
  SELECT LENGTH(store_id), store_address FROM stores
    WHERE LENGTH(store_id) < 5;
  ----------------------------------------------
  SELECT * FROM STORES;
  ----------------------------------------------
  
  
  
-- (e) - TESTING FOR NULLs

  /*Get all phone brands and types with NULL colour input*/
  SELECT phone_brand, phone_type, colour 
    FROM DT211C2A5.phone_specs
    WHERE colour IS NULL;
  ----------------------------------------------
  SELECT * FROM PHONE_SPECS;
  ----------------------------------------------
    
  
  
-- (f) - aggregation with GROUP BY and HAVING

  /*select phone brand from phone specs and group by
  phone brand with a max price less than 750*/
  SELECT phone_brand FROM DT211C2A5.phone_specs
    GROUP BY phone_brand 
      HAVING MAX(price) < 750;
  ----------------------------------------------
  SELECT * FROM PHONE_SPECS;
  ----------------------------------------------
  
  
  
-- (g) - MINUS, INTERSECTION and UNION

  /*MINUS - select supplier name from suppliers table,
  remove any phone brand from phone spec table that's in supliers name*/
  SELECT supplier_name FROM DT211C2A5.supplier
  MINUS
  SELECT phone_brand FROM DT211C2A5.phone_specs;
  
  /*INTERSECTION - select phone brands from phone specs table
  and supplier name from supplier table. Show what's the same in both tables*/
  SELECT phone_brand FROM DT211C2A5.phone_specs
  INTERSECT
  SELECT supplier_name FROM DT211C2A5.supplier;
  
  /*UNION - select phone brands from phone specs table
  and supplier name from supplier table. Show what's DISTINCT in both tables. */
  SELECT phone_brand FROM DT211C2A5.phone_specs
  UNION
  SELECT supplier_name FROM DT211C2A5.supplier;
  ----------------------------------------------
  SELECT * FROM PHONE_SPECS; 
  SELECT * FROM SUPPLIER;
  ----------------------------------------------
  


-- (h) - use of JOIN USING, JOIN ON and JOINS implemented through WHERE clause
  
  /* JOIN USING - select all from stores table and 
  join values in customer contract table that's common to stores table (left table)
  using store id, where the store id is
  *the USING keyword allows comparison only of same column names (store_id) */          
  SELECT * FROM DT211C2A5.stores LEFT JOIN DT211C2A5.cust_contract
    USING(store_id)
      WHERE store_id='2048';
  ----------------------------------------------
  SELECT * FROM STORES;
  SELECT * FROM CUST_CONTRACT; -- NEW
  ----------------------------------------------
  
  /*JOIN ON - select all from phone specs table and join all from suppliers table
  using phone brand on phone specs table that equals supplier name on suppliers table,
  where the supplier names are Doro or iPhone
  *the ON keyword allows comparison of different column names (phone_brand & supplier_name) */
  SELECT * FROM DT211C2A5.phone_specs FULL OUTER JOIN DT211C2A5.supplier 
    ON PHONE_SPECS.phone_brand = SUPPLIER.supplier_name
      WHERE SUPPLIER.supplier_name = 'Doro' OR
            SUPPLIER.supplier_name = 'iPhone';
  ----------------------------------------------
  SELECT * FROM PHONE_SPECS; 
  SELECT * FROM SUPPLIER;
  ----------------------------------------------
  
  
  
-- (i) - USE OF OUTER JOINS

  /* select all from phone specs table and join all from suppliers table
  using phone brand on phone specs table that equals supplier name on suppliers table,
  where price from phone specs table is greater than 0, order the price in descending order */
  SELECT * FROM DT211C2A5.phone_specs FULL OUTER JOIN DT211C2A5.supplier 
    ON PHONE_SPECS.phone_brand = SUPPLIER.supplier_name
      WHERE PHONE_SPECS.price > 0 
        ORDER BY PHONE_SPECS.price DESC;
  ----------------------------------------------
  SELECT * FROM PHONE_SPECS; 
  SELECT * FROM SUPPLIER;
  ----------------------------------------------
  


-- (j) - USE OF SUB-QUERIES

  /* SUB QUERY - select all from stores where there is a store id sub query
                 select store id of contract no: 1234568 */
  SELECT * FROM DT211C2A5.stores
      WHERE store_id IN (SELECT store_id 
                          FROM DT211C2A5.cust_contract 
                            WHERE contract_no = 1234568);
                            

  ----------------------------------------------
  SELECT * FROM STORES;
  SELECT * FROM CUST_CONTRACT;
  ----------------------------------------------
  
  
  
-- (k) - An appropriate query to the role
  /* using a serial number to update the colour of a handset */
  UPDATE DT211C2A5.phone_specs
      SET colour = 'White'
        WHERE serial_no IN (SELECT serial_no 
                            FROM DT211C2A5.phone_specs
                              WHERE serial_no = 746864646461992);
  -- Revert to original                
  UPDATE DT211C2A5.phone_specs
      SET colour = ''
        WHERE serial_no IN (SELECT serial_no 
                            FROM DT211C2A5.phone_specs
                              WHERE serial_no = 746864646461992);
  ----------------------------------------------
  SELECT * FROM PHONE_SPECS;
  ----------------------------------------------