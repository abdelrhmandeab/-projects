
import java.awt.Image;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */

/**
 *
 * @author abdel
 */
public class item extends javax.swing.JFrame {

    /**
     * Creates new form item
     */
    public item() {
        initComponents();
        try {
            Image img = ImageIO.read(getClass().getResource("/images/hospital.png"));
            this.setIconImage(img);
        } catch (IOException ex) {
            Logger.getLogger(main.class.getName()).log(Level.SEVERE, null, ex);
        }
        connect();
        autoid();
        item_table();
    }
Connection con;
PreparedStatement pst;
ResultSet rs;

public void connect(){
    
        String currentdir=System.getProperty("user.dir");
            try {
                Class.forName("org.h2.Driver");
            con= DriverManager.getConnection("jdbc:h2:"+currentdir+"\\hms_db\\HMS","","");
            } catch (SQLException | ClassNotFoundException ex) {
                Logger.getLogger(login.class.getName()).log(Level.SEVERE, null, ex);
            }
}

public void autoid(){

        try {
           Statement s = con.createStatement();
           rs = s.executeQuery("select MAX(itemid) from item");
           rs.next();
           rs.getString(1);
           
           if(rs.getString(1)==null){
               lblitemid12.setText("IU001");
           }
           else{
               long id =Long.parseLong(rs.getString(1).substring(2, rs.getString(1).length()));
               id++;
               lblitemid12.setText("IU"+String.format("%03d",id));
           }
        } catch (SQLException ex) {
            Logger.getLogger(patient.class.getName()).log(Level.SEVERE, null, ex);
        }
    
}

    @SuppressWarnings("unchecked")
    public void item_table(){

        try {
            pst = con.prepareStatement("select * from item");
            rs = pst.executeQuery();
            ResultSetMetaData rsm = rs.getMetaData();
            int c;
            c=rsm.getColumnCount();
            
            DefaultTableModel df = (DefaultTableModel) jTable13.getModel();
            df.setRowCount(0);
            
            while(rs.next()){
                Vector v2 = new Vector();
                
                for(int i =1;i<=c;i++){
                v2.add(rs.getString("itemid"));
                v2.add(rs.getString("itemname"));
                v2.add(rs.getString("description"));
                v2.add(rs.getInt("sellprice"));
                v2.add(rs.getInt("buyprice"));
                v2.add(rs.getInt("qty"));
                }
                df.addRow(v2);
            }
        } catch (SQLException ex) {
            Logger.getLogger(patient.class.getName()).log(Level.SEVERE, null, ex);
        }
}
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel14 = new javax.swing.JPanel();
        jLabel73 = new javax.swing.JLabel();
        jLabel74 = new javax.swing.JLabel();
        jLabel75 = new javax.swing.JLabel();
        jLabel76 = new javax.swing.JLabel();
        txtname12 = new javax.swing.JTextField();
        lblitemid12 = new javax.swing.JLabel();
        txtdes12 = new javax.swing.JTextField();
        jScrollPane14 = new javax.swing.JScrollPane();
        jTable13 = new javax.swing.JTable();
        jLabel77 = new javax.swing.JLabel();
        jLabel78 = new javax.swing.JLabel();
        txtsellprice12 = new javax.swing.JTextField();
        txtbuyprice12 = new javax.swing.JTextField();
        txtqty12 = new javax.swing.JTextField();
        jButton5 = new javax.swing.JButton();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setBackground(new java.awt.Color(153, 204, 255));

        jPanel14.setBackground(new java.awt.Color(153, 204, 255));
        jPanel14.setBorder(javax.swing.BorderFactory.createTitledBorder(null, "Item creation", javax.swing.border.TitledBorder.CENTER, javax.swing.border.TitledBorder.TOP, new java.awt.Font("Arial Black", 1, 24))); // NOI18N

        jLabel73.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jLabel73.setText("Item id");

        jLabel74.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jLabel74.setText("Item Name");

        jLabel75.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jLabel75.setText("Description");

        jLabel76.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jLabel76.setText("Sell price");

        lblitemid12.setFont(new java.awt.Font("Arial", 1, 18)); // NOI18N
        lblitemid12.setText("jLabel5");

        jTable13.setBackground(new java.awt.Color(153, 204, 255));
        jTable13.setFont(new java.awt.Font("Arial", 0, 12)); // NOI18N
        jTable13.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null, null, null},
                {null, null, null, null, null, null},
                {null, null, null, null, null, null},
                {null, null, null, null, null, null}
            },
            new String [] {
                "Item id", "Item Name", "Description", "Sell price", "Buy price", "QTY"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.Integer.class, java.lang.Integer.class, java.lang.Integer.class
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }
        });
        jTable13.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                jTable13MouseClicked(evt);
            }
        });
        jScrollPane14.setViewportView(jTable13);

        jLabel77.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jLabel77.setText("Buy price");

        jLabel78.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jLabel78.setText("QTY");

        jButton5.setText("Exit");
        jButton5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton5ActionPerformed(evt);
            }
        });

        jButton1.setText("Add");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setText("Update");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jButton3.setText("Delete");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel14Layout = new javax.swing.GroupLayout(jPanel14);
        jPanel14.setLayout(jPanel14Layout);
        jPanel14Layout.setHorizontalGroup(
            jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel14Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel14Layout.createSequentialGroup()
                        .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel14Layout.createSequentialGroup()
                                .addGap(87, 87, 87)
                                .addComponent(txtdes12, javax.swing.GroupLayout.PREFERRED_SIZE, 181, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(jPanel14Layout.createSequentialGroup()
                                .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel75)
                                    .addComponent(jLabel76)
                                    .addComponent(jLabel74)
                                    .addComponent(jLabel77)
                                    .addComponent(jLabel78, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jLabel73))
                                .addGap(7, 7, 7)
                                .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(lblitemid12)
                                    .addComponent(txtname12, javax.swing.GroupLayout.PREFERRED_SIZE, 181, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                        .addComponent(txtsellprice12, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 71, Short.MAX_VALUE)
                                        .addComponent(txtbuyprice12, javax.swing.GroupLayout.Alignment.LEADING)
                                        .addComponent(txtqty12, javax.swing.GroupLayout.Alignment.LEADING)))))
                        .addGap(18, 18, 18)
                        .addComponent(jScrollPane14, javax.swing.GroupLayout.DEFAULT_SIZE, 496, Short.MAX_VALUE))
                    .addGroup(jPanel14Layout.createSequentialGroup()
                        .addComponent(jButton1)
                        .addGap(18, 18, 18)
                        .addComponent(jButton2)
                        .addGap(18, 18, 18)
                        .addComponent(jButton3)
                        .addGap(18, 18, 18)
                        .addComponent(jButton5)
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jPanel14Layout.setVerticalGroup(
            jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel14Layout.createSequentialGroup()
                .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jScrollPane14, javax.swing.GroupLayout.PREFERRED_SIZE, 344, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel14Layout.createSequentialGroup()
                        .addGap(40, 40, 40)
                        .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel73)
                            .addComponent(lblitemid12))
                        .addGap(34, 34, 34)
                        .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel74)
                            .addComponent(txtname12, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(34, 34, 34)
                        .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel75)
                            .addComponent(txtdes12, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(41, 41, 41)
                        .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel76)
                            .addComponent(txtsellprice12, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(29, 29, 29)
                        .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel77)
                            .addComponent(txtbuyprice12, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(34, 34, 34)
                        .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel78)
                            .addComponent(txtqty12, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addGap(18, 18, 18)
                .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton1)
                    .addComponent(jButton2)
                    .addComponent(jButton3)
                    .addComponent(jButton5))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel14, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel14, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed

        String ino = lblitemid12.getText();

        try {
            pst = con.prepareStatement("delete from item where itemid =?");

            pst.setString(1, ino);
            pst.executeUpdate();

            JOptionPane.showMessageDialog(this,"patient deleted successfully");

            autoid();
            txtname12.setText("");
            txtdes12.setText("");
            txtsellprice12.setText("");
            txtbuyprice12.setText("");
            txtqty12.setText("");
            txtname12.requestFocus();
            item_table();
            jButton1.setEnabled(true);

        } catch (SQLException ex) {
            Logger.getLogger(patient.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jButton3ActionPerformed
    private void jButton5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton5ActionPerformed
        this.setVisible(false);
    }//GEN-LAST:event_jButton5ActionPerformed

    private void jTable13MouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jTable13MouseClicked
        DefaultTableModel d1 = (DefaultTableModel) jTable13.getModel();
        int selectedindex = jTable13.getSelectedRow();

        lblitemid12.setText(d1.getValueAt(selectedindex,0).toString());
        txtname12.setText(d1.getValueAt(selectedindex,1).toString());
        txtdes12.setText(d1.getValueAt(selectedindex,2).toString());
        txtsellprice12.setText(d1.getValueAt(selectedindex,3).toString());
        txtbuyprice12.setText(d1.getValueAt(selectedindex,4).toString());
        txtqty12.setText(d1.getValueAt(selectedindex,5).toString());

        jButton1.setEnabled(false);
    }//GEN-LAST:event_jTable13MouseClicked

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed

        String ino = lblitemid12.getText();
        String iname = txtname12.getText();
        String description = txtdes12.getText();
        String sellprice = txtsellprice12.getText();
        String buyprice = txtbuyprice12.getText();
        String qty = txtqty12.getText();

        try {
                PreparedStatement check = con.prepareStatement("select * from item where itemname=? and description=? and sellprice=? and buyprice= ? and qty=?"); 
                check.setString(1, iname);
                check.setString(2, description);
                check.setString(3, sellprice);
                check.setString(4, buyprice);
                check.setString(5, qty);
                rs = check.executeQuery(); 
                 if (rs.next()) { 
                    JOptionPane.showMessageDialog(this,"item already exists");
                    txtname12.setText("");
                    txtdes12.setText("");
                    txtsellprice12.setText("");
                    txtbuyprice12.setText("");
                    txtqty12.setText("");
                    txtname12.requestFocus();
                                 } 
                 else {
            pst = con.prepareStatement("insert into item(itemid,itemname,description,sellprice,buyprice,qty)values(?,?,?,?,?,?)");
            pst.setString(1, ino);
            pst.setString(2, iname);
            pst.setString(3, description);
            pst.setString(4, sellprice);
            pst.setString(5, buyprice);
            pst.setString(6, qty);
            pst.executeUpdate();

            JOptionPane.showMessageDialog(this,"item added successfully");

            autoid();
            txtname12.setText("");
            txtdes12.setText("");
            txtsellprice12.setText("");
            txtbuyprice12.setText("");
            txtqty12.setText("");
            txtname12.requestFocus();
            item_table();
                 }
        } catch (SQLException ex) {
            Logger.getLogger(patient.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed

        String ino = lblitemid12.getText();
        String iname = txtname12.getText();
        String description = txtdes12.getText();
        String sellprice = txtsellprice12.getText();
        String buyprice = txtbuyprice12.getText();
        String qty = txtqty12.getText();

        try {
                PreparedStatement check = con.prepareStatement("select * from item where itemname=? and description=? and sellprice=? and buyprice= ? and qty=?"); 
                pst.setString(1, iname);
                pst.setString(2, description);
                pst.setString(3, sellprice);
                pst.setString(4, buyprice);
                pst.setString(5, qty);
                rs = check.executeQuery(); 
                 if (rs.next()) { 
                    JOptionPane.showMessageDialog(this,"item already exists");
                    txtname12.setText("");
                    txtdes12.setText("");
                    txtsellprice12.setText("");
                    txtbuyprice12.setText("");
                    txtqty12.setText("");
                    txtname12.requestFocus();
                                 } 
                 else {
            pst = con.prepareStatement("update item set itemname = ?,description = ? ,sellprice = ?,buyprice = ?, qty=? where itemid = ?");

            pst.setString(1, iname);
            pst.setString(2, description);
            pst.setString(3, sellprice);
            pst.setString(4, buyprice);
            pst.setString(5, qty);
            pst.setString(6, ino);
            pst.executeUpdate();

            JOptionPane.showMessageDialog(this,"item updated successfully");

            autoid();
            txtname12.setText("");
            txtdes12.setText("");
            txtsellprice12.setText("");
            txtbuyprice12.setText("");
            txtqty12.setText("");
            txtname12.requestFocus();
            item_table();
            jButton1.setEnabled(true);
                 }
        } catch (SQLException ex) {
            Logger.getLogger(patient.class.getName()).log(Level.SEVERE, null, ex);
        }        // TODO add your handling code here:
    }//GEN-LAST:event_jButton2ActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(item.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(item.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(item.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(item.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(() -> {
            new item().setVisible(true);
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton5;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel13;
    private javax.swing.JLabel jLabel14;
    private javax.swing.JLabel jLabel15;
    private javax.swing.JLabel jLabel16;
    private javax.swing.JLabel jLabel17;
    private javax.swing.JLabel jLabel18;
    private javax.swing.JLabel jLabel19;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel20;
    private javax.swing.JLabel jLabel21;
    private javax.swing.JLabel jLabel22;
    private javax.swing.JLabel jLabel23;
    private javax.swing.JLabel jLabel24;
    private javax.swing.JLabel jLabel25;
    private javax.swing.JLabel jLabel26;
    private javax.swing.JLabel jLabel27;
    private javax.swing.JLabel jLabel28;
    private javax.swing.JLabel jLabel29;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel30;
    private javax.swing.JLabel jLabel31;
    private javax.swing.JLabel jLabel32;
    private javax.swing.JLabel jLabel33;
    private javax.swing.JLabel jLabel34;
    private javax.swing.JLabel jLabel35;
    private javax.swing.JLabel jLabel36;
    private javax.swing.JLabel jLabel37;
    private javax.swing.JLabel jLabel38;
    private javax.swing.JLabel jLabel39;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel40;
    private javax.swing.JLabel jLabel41;
    private javax.swing.JLabel jLabel42;
    private javax.swing.JLabel jLabel43;
    private javax.swing.JLabel jLabel44;
    private javax.swing.JLabel jLabel45;
    private javax.swing.JLabel jLabel46;
    private javax.swing.JLabel jLabel47;
    private javax.swing.JLabel jLabel48;
    private javax.swing.JLabel jLabel49;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel50;
    private javax.swing.JLabel jLabel51;
    private javax.swing.JLabel jLabel52;
    private javax.swing.JLabel jLabel53;
    private javax.swing.JLabel jLabel54;
    private javax.swing.JLabel jLabel55;
    private javax.swing.JLabel jLabel56;
    private javax.swing.JLabel jLabel57;
    private javax.swing.JLabel jLabel58;
    private javax.swing.JLabel jLabel59;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel60;
    private javax.swing.JLabel jLabel61;
    private javax.swing.JLabel jLabel62;
    private javax.swing.JLabel jLabel63;
    private javax.swing.JLabel jLabel64;
    private javax.swing.JLabel jLabel65;
    private javax.swing.JLabel jLabel66;
    private javax.swing.JLabel jLabel67;
    private javax.swing.JLabel jLabel68;
    private javax.swing.JLabel jLabel69;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel70;
    private javax.swing.JLabel jLabel71;
    private javax.swing.JLabel jLabel72;
    private javax.swing.JLabel jLabel73;
    private javax.swing.JLabel jLabel74;
    private javax.swing.JLabel jLabel75;
    private javax.swing.JLabel jLabel76;
    private javax.swing.JLabel jLabel77;
    private javax.swing.JLabel jLabel78;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JPanel jPanel10;
    private javax.swing.JPanel jPanel11;
    private javax.swing.JPanel jPanel12;
    private javax.swing.JPanel jPanel13;
    private javax.swing.JPanel jPanel14;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JPanel jPanel4;
    private javax.swing.JPanel jPanel5;
    private javax.swing.JPanel jPanel6;
    private javax.swing.JPanel jPanel7;
    private javax.swing.JPanel jPanel8;
    private javax.swing.JPanel jPanel9;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane10;
    private javax.swing.JScrollPane jScrollPane11;
    private javax.swing.JScrollPane jScrollPane12;
    private javax.swing.JScrollPane jScrollPane13;
    private javax.swing.JScrollPane jScrollPane14;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JScrollPane jScrollPane4;
    private javax.swing.JScrollPane jScrollPane5;
    private javax.swing.JScrollPane jScrollPane6;
    private javax.swing.JScrollPane jScrollPane7;
    private javax.swing.JScrollPane jScrollPane8;
    private javax.swing.JScrollPane jScrollPane9;
    private javax.swing.JTable jTable1;
    private javax.swing.JTable jTable10;
    private javax.swing.JTable jTable11;
    private javax.swing.JTable jTable12;
    private javax.swing.JTable jTable13;
    private javax.swing.JTable jTable2;
    private javax.swing.JTable jTable3;
    private javax.swing.JTable jTable4;
    private javax.swing.JTable jTable5;
    private javax.swing.JTable jTable6;
    private javax.swing.JTable jTable7;
    private javax.swing.JTable jTable8;
    private javax.swing.JTable jTable9;
    private javax.swing.JLabel lblitemid;
    private javax.swing.JLabel lblitemid1;
    private javax.swing.JLabel lblitemid10;
    private javax.swing.JLabel lblitemid11;
    private javax.swing.JLabel lblitemid12;
    private javax.swing.JLabel lblitemid2;
    private javax.swing.JLabel lblitemid3;
    private javax.swing.JLabel lblitemid4;
    private javax.swing.JLabel lblitemid5;
    private javax.swing.JLabel lblitemid6;
    private javax.swing.JLabel lblitemid7;
    private javax.swing.JLabel lblitemid8;
    private javax.swing.JLabel lblitemid9;
    private javax.swing.JTextField txtbuyprice;
    private javax.swing.JTextField txtbuyprice1;
    private javax.swing.JTextField txtbuyprice10;
    private javax.swing.JTextField txtbuyprice11;
    private javax.swing.JTextField txtbuyprice12;
    private javax.swing.JTextField txtbuyprice2;
    private javax.swing.JTextField txtbuyprice3;
    private javax.swing.JTextField txtbuyprice4;
    private javax.swing.JTextField txtbuyprice5;
    private javax.swing.JTextField txtbuyprice6;
    private javax.swing.JTextField txtbuyprice7;
    private javax.swing.JTextField txtbuyprice8;
    private javax.swing.JTextField txtbuyprice9;
    private javax.swing.JTextField txtdes;
    private javax.swing.JTextField txtdes1;
    private javax.swing.JTextField txtdes10;
    private javax.swing.JTextField txtdes11;
    private javax.swing.JTextField txtdes12;
    private javax.swing.JTextField txtdes2;
    private javax.swing.JTextField txtdes3;
    private javax.swing.JTextField txtdes4;
    private javax.swing.JTextField txtdes5;
    private javax.swing.JTextField txtdes6;
    private javax.swing.JTextField txtdes7;
    private javax.swing.JTextField txtdes8;
    private javax.swing.JTextField txtdes9;
    private javax.swing.JTextField txtname;
    private javax.swing.JTextField txtname1;
    private javax.swing.JTextField txtname10;
    private javax.swing.JTextField txtname11;
    private javax.swing.JTextField txtname12;
    private javax.swing.JTextField txtname2;
    private javax.swing.JTextField txtname3;
    private javax.swing.JTextField txtname4;
    private javax.swing.JTextField txtname5;
    private javax.swing.JTextField txtname6;
    private javax.swing.JTextField txtname7;
    private javax.swing.JTextField txtname8;
    private javax.swing.JTextField txtname9;
    private javax.swing.JTextField txtqty;
    private javax.swing.JTextField txtqty1;
    private javax.swing.JTextField txtqty10;
    private javax.swing.JTextField txtqty11;
    private javax.swing.JTextField txtqty12;
    private javax.swing.JTextField txtqty2;
    private javax.swing.JTextField txtqty3;
    private javax.swing.JTextField txtqty4;
    private javax.swing.JTextField txtqty5;
    private javax.swing.JTextField txtqty6;
    private javax.swing.JTextField txtqty7;
    private javax.swing.JTextField txtqty8;
    private javax.swing.JTextField txtqty9;
    private javax.swing.JTextField txtsellprice;
    private javax.swing.JTextField txtsellprice1;
    private javax.swing.JTextField txtsellprice10;
    private javax.swing.JTextField txtsellprice11;
    private javax.swing.JTextField txtsellprice12;
    private javax.swing.JTextField txtsellprice2;
    private javax.swing.JTextField txtsellprice3;
    private javax.swing.JTextField txtsellprice4;
    private javax.swing.JTextField txtsellprice5;
    private javax.swing.JTextField txtsellprice6;
    private javax.swing.JTextField txtsellprice7;
    private javax.swing.JTextField txtsellprice8;
    private javax.swing.JTextField txtsellprice9;
    // End of variables declaration//GEN-END:variables
}
