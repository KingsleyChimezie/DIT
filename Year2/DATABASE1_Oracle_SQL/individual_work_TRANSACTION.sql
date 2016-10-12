/*  Kingsley Chimezie - C14468272
    Case Study Part 2 - Individual work
    TRANSACTION
    09/05/16
*/
  
  --SELECT * FROM DT211C2A5.phone_specs;        -- view PHONE_SPECS table
  --SELECT * FROM DT211C2A5.supplier;           -- view SUPPLIER table
  --SELECT * FROM DT211C2A5.stores;             -- view SUPPLIER table
  
SET SERVEROUTPUT ON;                         
--SET TRANSACTION NAME 'specs_update';
  DECLARE                                     /* VARIABLES */             
    type_total INTEGER := 0;                  -- stores a total phone type of a brand
    comp_name VARCHAR2(100) := 'Huawei';      -- stores a supplier name
    new_address VARCHAR2(100) := 'France';    -- stores a supplier address
    
  BEGIN
    
    DBMS_OUTPUT.ENABLE;                       -- enable console printing
    
    
    /* PHONE_SPECS - using variable to view table information */
    SAVEPOINT SP1;
      
      
      -- delete inserted values into phone_specs table, from this save point
      DELETE FROM DT211C2A5.phone_specs WHERE serial_no = 746864646462016;
      DELETE FROM DT211C2A5.phone_specs WHERE serial_no = 746864646462014;
      
      -- use type_total variable to show amount of phone_types by a phone_brand BEFORE insert
      SELECT COUNT(phone_type) INTO type_total FROM DT211C2A5.phone_specs
        WHERE phone_brand = 'Huawei';
          DBMS_OUTPUT.PUT_LINE('phone_specs table had   ' || type_total || '    phone_type by HUAWEI');
      
      -- insert 2 more phone types
      INSERT INTO DT211C2A5.phone_specs VALUES
        (746864646462016,'Huawei','GX8','13mp','','3000',399);
      INSERT INTO DT211C2A5.phone_specs VALUES
        (746864646462014,'Huawei','Y3','8mp','','1800',69);
       
      -- use type_total variable to show amount of phone_types by a phone_brand AFTER insert
      SELECT COUNT(phone_type) INTO type_total FROM DT211C2A5.phone_specs
        WHERE phone_brand = 'Huawei';
          DBMS_OUTPUT.PUT_LINE('phone_specs table has   ' || type_total || '    phone_type by HUAWEI');
      
    
    /* SUPPLIER - using variables to change table information */
    SAVEPOINT SP2;
      UPDATE DT211C2A5.supplier
        SET supplier_address = new_address
          WHERE supplier_name = comp_name; 
        
        
    /* STORE - used to show error handling when insert is performed*/
    SAVEPOINT SP3;
       --INSERT INTO DT211C2A5.stores VALUES (4322,'N/A', 353000000000);
       --DELETE FROM DT211C2A5.stores WHERE store_id = '0000';
    
    
    EXCEPTION WHEN OTHERS
      THEN    
        DBMS_OUTPUT.PUT_LINE('****** ERROR FOUND ******:   ' || SQLERRM);  -- display error
        
  END;