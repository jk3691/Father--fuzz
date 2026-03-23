import streamlit as st
import requests

# Page Config for Mobile
st.set_page_config(page_title="Father-Fuzz Mobile", page_icon="🛡️")

st.title("🛡️ Father-Fuzz")
st.subheader("Web Directory Discovery")

# User Inputs (Replacing terminal input())
target = st.text_input("Target URL", placeholder="https://example.com")
wordlist_text = st.text_area("Wordlist (Enter paths, one per line)", "admin\nlogin\nconfig\napi\n.env")

if st.button("Start Scan"):
    if not target:
        st.warning("Please enter a target URL.")
    else:
        words = wordlist_text.splitlines()
        found_count = 0
        
        st.info(f"Scanning {len(words)} paths on {target}...")
        progress_bar = st.progress(0)
        
        # Simple loop for discovery
        for i, word in enumerate(words):
            # Clean URL formatting
            clean_url = target.rstrip('/')
            url = f"{clean_url}/{word.lstrip('/')}"
            
            try:
                # 5-second timeout to prevent app hanging
                r = requests.get(url, timeout=5)
                if r.status_code == 200:
                    st.success(f"✅ Found: {url}")
                    found_count += 1
            except Exception as e:
                # Silently skip connection errors to keep the scan moving
                pass
            
            # Update progress
            progress_bar.progress((i + 1) / len(words))
        
        st.write(f"Scan Complete. {found_count} directories found.")

st.divider()
st.caption("Educational purposes only. Ensure you have permission to scan the target.")
