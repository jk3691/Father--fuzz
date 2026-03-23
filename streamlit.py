import streamlit as st

# 1. Page Setup
st.set_page_config(page_title="Mandela Effect: Guitar Pedal", layout="centered")

# 2. Sidebar - System Controls
st.sidebar.title("🎛️ Pedal Rack")
st.sidebar.info("Model: The Dark Father (v1.0)")
power = st.sidebar.toggle("Power On/Off", value=True)

# 3. Main Interface - The Stompbox
st.title("Mandela Series")
st.header("The Dark Father")

if power:
    # Visual Knobs (Sliders)
    col1, col2 = st.columns(2)
    
    with col1:
        gain = st.select_slider("GAIN", options=[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10], value=5)
        tone = st.slider("TONE", 0, 100, 50)
        
    with col2:
        level = st.slider("LEVEL", 0, 100, 70)
        compression = st.select_slider("COMP", options=["Soft", "Hard", "Clipped"], value="Soft")

    st.divider()

    # 4. Status (Instead of Chat)
    st.subheader("Signal Status")
    if st.button("STOMP", type="primary"):
        st.success(f"ACTIVE: Gain {gain} | Tone {tone} | Level {level}")
        st.toast("Effect Engaged!")
    else:
        st.warning("BYPASS MODE")

else:
    st.error("Pedal is Powered Off.")
    st.info("Flip the switch in the sidebar to start.")
