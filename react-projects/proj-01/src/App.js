import "./App.css";
import Accordian from "./components/accordian";
import RandomColor from "./components/random-color";
import StarRating from "./components/star-rating";
import ImageSlider from "./components/image-slider";
import LoadMoreData from "./components/load-more-data";
import TreeView from "./components/tree-view";
import menus from "./components/tree-view/data";
import QrCodeGenerator from "./components/qr-code-generator/"

function App() {
  return (
    <div className="App">
      {/* Accordian component */}
      {/* <Accordian /> */}

      {/* RandomColor component */}
      {/* <RandomColor /> */}

      {/* StarRating component */}
      {/* <StarRating noOfStars={10}/> */}

      {/* ImageSlider component */}
      {/* <ImageSlider url={"https://picsum.photos/v2/list/"} limit={"10"} page={"1"} /> */}

      {/* Load more products component */}
      {/* <LoadMoreData /> */}

      {/* Load more products component / recursive navigation menu */}
      {/* <TreeView menus={menus} /> */}

      {/* QR Code Generator */}
      <QrCodeGenerator/>
    </div>
  );
}

export default App;
