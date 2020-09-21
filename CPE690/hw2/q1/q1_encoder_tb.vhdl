BEGIN
    uut: pr_encoder PORT MAP (
        S0 => S0,
        S1 => S1,
        S2 => S2,
        S3 => S3,
        Z => Z
    );
    s0_waveform: process is
    begin
        S0<='0', '1' after 20ns;
        wait for 40ns;
        end process;
    
    s1_waveform: process is
    begin
        S1<='0', '1' after 40ns;
        wait for 80ns;
    end process;
    
    s2_waveform: process is
    begin
        S2<='0', '1' after 80ns;
        wait for 160ns;
    end process;
    
    s3_waveform: process is
    begin
        S3<='0', '1' after 160ns;
        wait for 320ns;
    end process;
END;